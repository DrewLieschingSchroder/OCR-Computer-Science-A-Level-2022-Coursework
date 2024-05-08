#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <time.h>

namespace OCS
{
	class Enemy
	{
	public:
		Enemy(GameDataRef data);
		//enemy spawn function
		void SpawnEnemyA();
		void SpawnEnemyB();
		void SpawnEnemyC();
		void SpawnEnemyD();
		//score enemy spawn
		void SpawnScoreSprite();
		//movement fucntion
		void EnemyMove(float dt);
		//randomise offset
		void RandomiseEnemyOffset();
		//draw function
		void DrawEnemy();

		//reference to sprites
		const std::vector<sf::Sprite>& GetSpriteA() const;
		const std::vector<sf::Sprite>& GetSpriteB() const;
		const std::vector<sf::Sprite>& GetSpriteC() const;
		const std::vector<sf::Sprite>& GetSpriteD() const;
		
		//reference to score enemy
		std::vector<sf::Sprite>& GetScoringSprites();

	private:
		GameDataRef _data;
		//sprites for enemies
		std::vector<sf::Sprite> enemySpritesA;
		std::vector<sf::Sprite> enemySpritesB;
		std::vector<sf::Sprite> enemySpritesC;
		std::vector<sf::Sprite> enemySpritesD;
		//sprite for score enemy
		std::vector<sf::Sprite> scoringEnemy;
		//int values
		int _enemySpawnYOffset;
		int _enemySpawnXOffset;
		//float values, movement
		float eMove = eMoveMax;
		float eMoveMax = 100;
	};
}

