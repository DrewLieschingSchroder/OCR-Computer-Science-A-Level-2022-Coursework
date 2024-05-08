#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "LearnState.hpp"

namespace OCS
{
	class LearnTextD : public State
	{
	public:
		LearnTextD(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _learnText;
		sf::Sprite _malwareA;
		sf::Sprite _malwareB;
		sf::Sprite _malwareC;
		sf::Sprite _malwareD;
		sf::Sprite _backButton;
		sf::Sprite _textD;

	};
}
