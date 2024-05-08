#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.hpp"
#include <sstream>
#include "State.hpp"
#include "Game.hpp"
#include "GameOverState.hpp"
#include "MovingBackground.hpp"
#include "Player.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "GUI.hpp"
#include "Enemy.hpp"

namespace OCS
{
	class GameState : public State
	{
	public:
		//constructor
		GameState(GameDataRef data);

		//state machine functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		//reference to struct
		GameDataRef _data;

		//sprite
		sf::Sprite _background;

		//dereferences
		MovingBackground* movebg;
		Player* player;
		Enemy* enemy;
		Flash* flash;
		GUI* gui;
		Collision collision;

		//clocks
		sf::Clock clock;
		sf::Clock clock2;
		sf::Clock clock3;

		//int values
		int _gameState;
		int _score;
	};
}