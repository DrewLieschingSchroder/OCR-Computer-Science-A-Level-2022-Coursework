#include "Enemy.hpp"
#include <iostream>

namespace OCS
{
	Enemy::Enemy(GameDataRef data) : _data(data)
	{
	}

	void Enemy::SpawnEnemyA()
	{
		//texture loaded
		_data->assets.LoadTexture("Enemy A", ENEMY_A_FILEPATH);
		//texture set to sprite
		sf::Sprite sprite(_data->assets.GetTexture("Enemy A"));
		//set position
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _enemySpawnYOffset);
		//enemy push back
		enemySpritesA.push_back(sprite);
	}
	void Enemy::SpawnEnemyB()
	{
		_data->assets.LoadTexture("Enemy B", ENEMY_B_FILEPATH);
		
		sf::Sprite sprite(_data->assets.GetTexture("Enemy B"));

		sprite.setPosition(0, _enemySpawnYOffset );

		enemySpritesB.push_back(sprite);
	}
	void Enemy::SpawnEnemyC()
	{
		_data->assets.LoadTexture("Enemy C", ENEMY_C_FILEPATH);
		
		sf::Sprite sprite(_data->assets.GetTexture("Enemy C"));

		sprite.setPosition(_enemySpawnXOffset, -100);

		enemySpritesC.push_back(sprite);
	}
	void Enemy::SpawnEnemyD()
	{
		_data->assets.LoadTexture("Enemy D", ENEMY_D_FILEPATH);

		sf::Sprite sprite(_data->assets.GetTexture("Enemy D"));

		sprite.setPosition(0, -300);

		enemySpritesD.push_back(sprite);
	}
	
	void Enemy::SpawnScoreSprite()
	{
		_data->assets.LoadTexture("Scoring Enemy", SCORING_ENEMY_FILEPATH);

		sf::Sprite sprite(_data->assets.GetTexture("Scoring Enemy"));

		sprite.setPosition(0,0);

		scoringEnemy.push_back(sprite);
	}

	
	void Enemy::EnemyMove(float dt)
	{
		//eMove will increase until larger than eMoveMax, before having its value decreased
		eMove += 0.5f;
		if (eMove >= eMoveMax)
		{
			eMove = -0.2f;
		}
	
		for (unsigned short int i = 0; i < enemySpritesA.size(); i++)
		{
			if (enemySpritesA.at(i).getPosition().x < 0 - enemySpritesA.at(i).getGlobalBounds().width)
			{
				enemySpritesA.erase(enemySpritesA.begin() + i);
			}
			else
			{
				//frame rate consistenet movement
				float movement = ENEMY_MOVEMENT_SPEED * dt;
				//sprite movement
				enemySpritesA.at(i).move(-movement , 0);
			}
		}
		for (unsigned short int i = 0; i < enemySpritesC.size(); i++)
		{
			if (enemySpritesC.at(i).getPosition().y > _data->window.getSize().y + enemySpritesC.at(i).getGlobalBounds().height)
			{
				enemySpritesC.erase(enemySpritesC.begin() + i);
			}
			else
			{
				float movement = ENEMY_MOVEMENT_SPEED_2 * dt;

				enemySpritesC.at(i).move(20*sin(eMove), movement);
			}
		}
		for (unsigned short int i = 0; i < enemySpritesB.size(); i++)
		{
			if (enemySpritesB.at(i).getPosition().y > _data->window.getSize().y + enemySpritesB.at(i).getGlobalBounds().height)
			{
				enemySpritesB.erase(enemySpritesB.begin() + i);
			}
			else
			{
				float movement = ENEMY_MOVEMENT_SPEED * dt;
				
				enemySpritesB.at(i).move(sin( 0.5) + eMove / 10, 1 / movement);
				
			}
		}
		for (unsigned short int i = 0; i < enemySpritesD.size(); i++)
		{
			if (enemySpritesD.at(i).getPosition().y > _data->window.getSize().y + enemySpritesD.at(i).getGlobalBounds().height)
			{
				enemySpritesD.erase(enemySpritesD.begin() + i);
			}
			else
			{
				float movement = ENEMY_MOVEMENT_SPEED * dt;

				enemySpritesD.at(i).move(0, movement);
			}
		}
		

		//std::cout << enemySpritesX2.size() << std::endl;

		for (unsigned short int i = 0; i < scoringEnemy.size(); i++)
		{
			if (scoringEnemy.at(i).getPosition().y > _data->window.getSize().y + scoringEnemy.at(i).getGlobalBounds().height)
			{
				scoringEnemy.erase(scoringEnemy.begin() + i);
			}
			else
			{
				float movement = ENEMY_MOVEMENT_SPEED * dt;

				scoringEnemy.at(i).move(0, movement);
			}

		}
		//std::cout << scoringEnemy.size() << std::endl;
	}

	void Enemy::RandomiseEnemyOffset()
	{
		//random value in the range 0 to 588
		_enemySpawnYOffset = rand() % (SCREEN_HEIGHT - 200);
		//random value in the range 0 to 1400 
		_enemySpawnXOffset = rand() % (SCREEN_WIDTH);
	}

	void Enemy::DrawEnemy()
	{
		for (unsigned short int i = 0; i < enemySpritesA.size(); i++)
		{
			_data->window.draw(enemySpritesA.at(i));
		}

		for (unsigned short int i = 0; i < enemySpritesC.size(); i++)
		{
			_data->window.draw(enemySpritesC.at(i));
		}

		for (unsigned short int i = 0; i < enemySpritesB.size(); i++)
		{
			_data->window.draw(enemySpritesB.at(i));
		}

		for (unsigned short int i = 0; i < enemySpritesD.size(); i++)
		{
			_data->window.draw(enemySpritesD.at(i));
		}
		
	}

	const std::vector<sf::Sprite>& Enemy::GetSpriteA() const
	{
		return enemySpritesA;
	}
	const std::vector<sf::Sprite>& Enemy::GetSpriteB() const
	{
		return enemySpritesB;
	}
	const std::vector<sf::Sprite>& Enemy::GetSpriteC() const
	{
		return enemySpritesC;
	}
	const std::vector<sf::Sprite>& Enemy::GetSpriteD() const
	{
		return enemySpritesD;
	}
	std::vector<sf::Sprite>& Enemy::GetScoringSprites()
	{
		return scoringEnemy;
	}
};