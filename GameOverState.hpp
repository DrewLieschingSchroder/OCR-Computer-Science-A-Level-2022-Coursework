#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include "MainMenuState.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

namespace OCS
{
	//class inherits from public state
	class GameOverState : public State
	{
	public:
		//constructor
		GameOverState(GameDataRef data, int score);
		//state machine functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		//struct reference
		GameDataRef _data;
		//sprite
		sf::Sprite _background;
		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;
		sf::Sprite _medal;
		//text
		sf::Text _scoreText;
		sf::Text _highScoreText;
		//int values
		int _score;
		int _highScore;
	};
}