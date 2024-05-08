#include <sstream>
#include <SFML/Audio.hpp>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "OptionState.hpp"
#include "LearnState.hpp"

#include <iostream>

namespace OCS
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

	void MainMenuState::Init()
	{
		//call textures from DEFINITIONS
		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BG_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Option Button", OPTION_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Learn Button", LEARN_BUTTON_FILEPATH);

		//set textures to sprites
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_optionButton.setTexture(this->_data->assets.GetTexture("Option Button"));
		_learnButton.setTexture(this->_data->assets.GetTexture("Learn Button"));

		//set position of sprites on menu screen
		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 10);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
		_optionButton.setPosition((SCREEN_WIDTH / 3) - (_optionButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_optionButton.getGlobalBounds().height / 2));
		_learnButton.setPosition((SCREEN_WIDTH / 1.5) - (_learnButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_learnButton.getGlobalBounds().height / 2));

		sf::Music music;
		if (!music.openFromFile("Music/menuMusic.ogg"))
			std::cout << "error" << "\n";
		music.play();
		music.setLoop(true);
	}

	void MainMenuState::HandleInput()
	{
		//event loop
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			//close window when close is clicked
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			//loads game state
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
			//load option state
			if (_data->input.IsSpriteClicked(_optionButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new OptionState(_data)), true);
			}
			//load learn state
			if (_data->input.IsSpriteClicked(_learnButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new LearnState(_data)), true);
			}
		}
	}
	void MainMenuState::Update(float dt)
	{
	}
	void MainMenuState::Draw(float dt)
	{
		//clear screen
		_data->window.clear();

		//draw sprites
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.draw(_optionButton);
		_data->window.draw(_learnButton);

		//display sprites
		_data->window.display();
	}
}