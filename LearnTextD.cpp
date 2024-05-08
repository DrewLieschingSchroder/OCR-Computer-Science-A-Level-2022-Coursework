#include "LearnTextD.hpp"


namespace OCS
{
	LearnTextD::LearnTextD(GameDataRef data) : _data(data)
	{
	}
	void LearnTextD::Init()
	{
		//load textures
		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Malware D", ENEMY_D_SMALL_FILEPATH);
		_data->assets.LoadTexture("Text D", LEARN_TEXT_D_FILEPATH);

		//set textures
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_malwareD.setTexture(this->_data->assets.GetTexture("Malware D"));
		_textD.setTexture(this->_data->assets.GetTexture("Text D"));

		//set position
		_backButton.setPosition((SCREEN_WIDTH / 2) - (_backButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_backButton.getGlobalBounds().height / 2));
		_malwareD.setPosition((SCREEN_WIDTH / 2) - (_malwareD.getGlobalBounds().width / 2), _malwareD.getGlobalBounds().height / 10);
		_textD.setPosition((SCREEN_WIDTH / 2) - (_textD.getGlobalBounds().width / 2), _textD.getGlobalBounds().height / 2);
	}
	void LearnTextD::HandleInput()
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
				_data->machine.AddState(StateRef(new LearnState(_data)), true);
			}

		}
	}
	void LearnTextD::Update(float dt)
	{
	}
	void LearnTextD::Draw(float dt)
	{
		//clear / draw / display
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_malwareD);
		_data->window.draw(_textD);
		_data->window.draw(_backButton);

		_data->window.display();
	}
}