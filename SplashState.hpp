#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"

namespace OCS
{
	//inherit from state
	class SplashState : public State
	{
	public:
		//constructor
		SplashState(GameDataRef data);

		//functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}