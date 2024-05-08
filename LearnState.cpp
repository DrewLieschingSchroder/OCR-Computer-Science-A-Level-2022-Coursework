#include "LearnState.hpp"


namespace OCS
{
	LearnState::LearnState(GameDataRef data) : _data(data)
	{
	}
	void LearnState::Init()
	{
		//load textures
		_data->assets.LoadTexture("Learn Text", LEARN_TEXT_FILEPATH);
		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);	
		_data->assets.LoadTexture("Malware A", ENEMY_AL_FILEPATH);
		_data->assets.LoadTexture("Malware B", ENEMY_BL_FILEPATH);
		_data->assets.LoadTexture("Malware C", ENEMY_CL_FILEPATH);
		_data->assets.LoadTexture("Malware D", ENEMY_DL_FILEPATH);

		//set textures
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_learnText.setTexture(this->_data->assets.GetTexture("Learn Text"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_malwareA.setTexture(this->_data->assets.GetTexture("Malware A"));
		_malwareB.setTexture(this->_data->assets.GetTexture("Malware B"));
		_malwareC.setTexture(this->_data->assets.GetTexture("Malware C"));
		_malwareD.setTexture(this->_data->assets.GetTexture("Malware D"));
		
		//set position
		_malwareA.setPosition((SCREEN_WIDTH / 3) - (_malwareA.getGlobalBounds().width / 2), _malwareA.getGlobalBounds().height / 10);
		_malwareB.setPosition((SCREEN_WIDTH / 1.5) - (_malwareB.getGlobalBounds().width / 2), _malwareB.getGlobalBounds().height / 10);
		_malwareC.setPosition((SCREEN_WIDTH / 3) - (_malwareC.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2.5) - _malwareC.getGlobalBounds().height / 7);
		_malwareD.setPosition((SCREEN_WIDTH / 1.5) - (_malwareD.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2.5) - _malwareD.getGlobalBounds().height / 7);
		_backButton.setPosition((SCREEN_WIDTH / 2) - (_backButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_backButton.getGlobalBounds().height / 2));
	}
	void LearnState::HandleInput()
	{
		sf::Event event;
		//event loop
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			//state change to menu
			if (_data->input.IsSpriteClicked(_backButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			//state change to education states
			if (_data->input.IsSpriteClicked(_malwareA, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new LearnTextA(_data)), true);
			}
			if (_data->input.IsSpriteClicked(_malwareB, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new LearnTextB(_data)), true);
			}
			if (_data->input.IsSpriteClicked(_malwareC, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new LearnTextC(_data)), true);
			}
			if (_data->input.IsSpriteClicked(_malwareD, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new LearnTextD(_data)), true);
			}
		}
	}
	void LearnState::Update(float dt)
	{
	}
	void LearnState::Draw(float dt)
	{
		//clear / draw / display
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_malwareA);
		_data->window.draw(_malwareB);
		_data->window.draw(_malwareC);
		_data->window.draw(_malwareD);
		_data->window.draw(_backButton);

		_data->window.display();
	}
}