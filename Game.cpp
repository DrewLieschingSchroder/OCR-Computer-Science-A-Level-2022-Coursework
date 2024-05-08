#include "Game.hpp"
#include "SplashState.hpp"

#include <stdlib.h>
#include <time.h>


namespace OCS
{
	Game::Game(int width, int height, std::string title)
	{

		srand(time(NULL));

		//create window
		// dimensions and style
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		//chooses starting state
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		//get time in seconds from when the clock first starts
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		//
		float accumulator = 0.0f;

		//while window is open
		while (this->_data->window.isOpen())
		{
			//will check to see if states have been changed at all
			this->_data->machine.ProcessStateChanges();

			//smooth gameplay if there is differing frame rates
			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			//restricting frame time to be no greater than 0.25
			if (frameTime > 0.25)
			{
				frameTime = 0.25;
			}

			currentTime = newTime;
			//accumulator is equal to all the frame times
			accumulator += frameTime;

			//make sure inputs and any updates are processed
			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}