#include <sstream>
#include "SplashState.hpp"

#include "DEFINITIONS.hpp"

#include <iostream>

namespace OCS
{
	//constructor
	SplashState::SplashState(GameDataRef data) : _data(data)
	{
	}
	//initialiser
	void SplashState::Init()
	{
		//calls texture
		_data->assets.LoadTexture("Splash State Background", SPLASH_STATE_BACKGROUND_FILEPATH);
		//sets texture to sprite
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		//set position of sprite on window
		_background.setPosition((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2));
	}

	void SplashState::HandleInput()
	{
		//event loop
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			//closes window if close is clicked
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}
	void SplashState::Update(float dt)
	{
		//after SPLASH_STATE_SHOW_TIME the main menu state loads
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
	//draw sprites to screen
	void SplashState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}
}