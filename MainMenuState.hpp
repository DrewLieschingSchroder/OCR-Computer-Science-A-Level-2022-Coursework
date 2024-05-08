#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace OCS
{
	//MainMenuState inherits from State class
	class MainMenuState : public State
	{
	public:
		//constructor
		MainMenuState(GameDataRef data);
		
		//state machine functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		//reference to struct
		GameDataRef _data;

		//sprites
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _optionButton;
		sf::Sprite _learnButton;
	};
}