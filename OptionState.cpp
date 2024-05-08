#include "OptionState.hpp"
#include <iostream>
#include "SFML/Audio.hpp"

namespace OCS
{
	OptionState::OptionState(GameDataRef data) : _data(data)
	{
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		_shape.setFillColor(sf::Color(_colourBlind, _colourBlind, 255, 0));


	}
	void OptionState::Init()
	{
		//load textures from definitions
		_data->assets.LoadTexture("Option", OPTION_FILEPATH);
		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Controls", OPTIONS_CONTROL_FILEPATH);
		//set textures to the sprites
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_option.setTexture(this->_data->assets.GetTexture("Option"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_controls.setTexture(this->_data->assets.GetTexture("Controls"));
		//set positions
		_option.setPosition((SCREEN_WIDTH / 2) - (_option.getGlobalBounds().width / 2), _option.getGlobalBounds().height / 10);
		_controls.setPosition((SCREEN_WIDTH / 2) - (_controls.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.65) - _controls.getGlobalBounds().height);
		_backButton.setPosition((SCREEN_WIDTH / 2) - (_backButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_backButton.getGlobalBounds().height / 2));
	}
	void OptionState::HandleInput()
	{
		//event loop
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			//change state to main menu
			if (_data->input.IsSpriteClicked(_backButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

			if (_data->input.IsSpriteClicked(_option, sf::Mouse::Left, _data->window))
			{
				if (!ENEMY_MOVEMENT_SPEED == 10.f)
					ENEMY_MOVEMENT_SPEED -20;
				if (!ENEMY_MOVEMENT_SPEED_2 == 10.f)
					ENEMY_MOVEMENT_SPEED_2 - 20;
			}
		}
	}
	void OptionState::Update(float dt)
	{

	}
	void OptionState::Draw(float dt)
	{
		//clear
		_data->window.clear();
		//draw
		_data->window.draw(_background);
		_data->window.draw(_option);
		_data->window.draw(_backButton);
		_data->window.draw(_controls);
		_data->window.draw(_shape);
		//display
		_data->window.display();
	}
}