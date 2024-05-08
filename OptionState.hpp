#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace OCS
{
	class OptionState : public State
	{
	public:
		OptionState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _option;
		sf::Sprite _controls;
		sf::Sprite _backButton;
		sf::RectangleShape _shape;
		

		int _colourBlind;

	};
}