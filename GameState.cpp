#include "GameState.hpp"

#include <iostream>

namespace OCS
{
	//constructor
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}
	//initialiser
	void GameState::Init()
	{
		//create new
		movebg = new MovingBackground(_data);
		player = new Player(_data);
		enemy = new Enemy(_data);
		flash = new Flash(_data);
		gui = new GUI(_data);

		//set texture to background sprite
		_data->assets.LoadTexture("Game State Background", GAME_STATE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));

		// update score function from gui class is called
		gui->UpdateScore(_score);

		//set game state to ready
		_gameState = GameStates::eReady;
	}

	void GameState::HandleInput()
	{
		//event loop
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void GameState::Update(float dt)
	{
		//if game state is not set to game over
		if (GameStates::eGameOver != _gameState)
		{
			//set game state to play
			_gameState = GameStates::ePlaying;
			
			//menu screen moves down
			movebg->MoveBackground(dt);

			//player movement, bounds, and animation
			player->Input();
			player->Bounds();
			player->Animate(dt);
		}
		//if gamestate is = playing
		if (GameStates::ePlaying == _gameState)
		{
			//enemy move function
			enemy->EnemyMove(dt);
			//enemy offset is randomised
			enemy->RandomiseEnemyOffset();
			//if clock is greater than enemy spawn value then...
			if (clock.getElapsedTime().asSeconds() > ENEMY_SPAWN_FREQUENCY_FAST)
			{
				//enemy spawns
				enemy->SpawnEnemyA();
				enemy->SpawnEnemyB();
				enemy->SpawnEnemyC();
				enemy->SpawnScoreSprite();
				
				//clock restart so the next enemies can spawn
				clock.restart();
			}
			//if clock is greater than enemy spawn value then...
			if (clock2.getElapsedTime().asSeconds() > ENEMY_SPAWN_FREQUENCY_SLOW)
			{
				//enemy spawns
				enemy->SpawnEnemyD();
				//clock restart so the next enemies can spawn
				clock2.restart();
			}
			//if enemy collides with player sprite then game state = over and clock restart
			std::vector<sf::Sprite> enemySpriteA = enemy->GetSpriteA();
			for (int i = 0; i < enemySpriteA.size(); i++)
			{
				if (collision.CheckSpriteCollision(player->GetSprite(), 0.625f, enemySpriteA.at(i), 0.65f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}
			//if enemy collides with player sprite then game state = over and clock restart
			std::vector<sf::Sprite> enemySpriteB = enemy->GetSpriteB();
			for (int i = 0; i < enemySpriteB.size(); i++)
			{
				if (collision.CheckSpriteCollision(player->GetSprite(), 0.625f, enemySpriteB.at(i), 0.65f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}
			//if enemy collides with player sprite then game state = over and clock restart
			std::vector<sf::Sprite> enemySpriteC = enemy->GetSpriteC();
			for (int i = 0; i < enemySpriteC.size(); i++)
			{
				if (collision.CheckSpriteCollision(player->GetSprite(), 0.625f, enemySpriteC.at(i), 0.65f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}
			//if enemy collides with player sprite then game state = over and clock restart
			std::vector<sf::Sprite> enemySpriteD = enemy->GetSpriteD();
			for (int i = 0; i < enemySpriteD.size(); i++)
			{
				if (collision.CheckSpriteCollision(player->GetSprite(), 0.625f, enemySpriteD.at(i), 0.65f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}
			//invisble enemy that is same size as window
			std::vector<sf::Sprite>& scoringSprites = enemy->GetScoringSprites();
			for (int i = 0; i < scoringSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(player->GetSprite(), scoringSprites.at(i)))
				{
					//on collision score will increase
					_score++;
					//the score will be updated on the screen
					gui->UpdateScore(_score);
					//the score enemy will be erased on collision
					//as it always collides with player, it is always erased
					scoringSprites.erase(scoringSprites.begin() + i);
				}
			}
		}
		//if game state = game over
		if (GameStates::eGameOver == _gameState)
		{
			//flash effect code runs
			flash->Show(dt);
			//clock reset on collsion so the clock will restart
			//this will give a set delay for every run
			if (clock.getElapsedTime().asSeconds() > GAMEOVER_DELAY)
			{
				//state is changed to game over state
				_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
			}
		}
	}

	//draw function
	void GameState::Draw(float dt)
	{
		//window clear
		_data->window.clear();
		//draw sprites to screen
		_data->window.draw(_background);
		enemy->DrawEnemy();
		player->Draw();
		movebg->DrawBackground();
		flash->Draw();
		gui->Draw();
		//display function
		_data->window.display();
	}
}