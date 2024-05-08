#include "LearnTextA.hpp"


namespace OCS
{
	LearnTextA::LearnTextA(GameDataRef data) : _data(data)
	{
	}
	void LearnTextA::Init()
	{
		//load textures
		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Malware A", ENEMY_A_FILEPATH);
		_data->assets.LoadTexture("Text A", LEARN_TEXT_A_FILEPATH);

		//set textures
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_malwareA.setTexture(this->_data->assets.GetTexture("Malware A"));
		_textA.setTexture(this->_data->assets.GetTexture("Text A"));

		//set position
		_backButton.setPosition((SCREEN_WIDTH / 2) - (_backButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_backButton.getGlobalBounds().height / 2));
		_malwareA.setPosition((SCREEN_WIDTH /2) - (_malwareA.getGlobalBounds().width / 2), _malwareA.getGlobalBounds().height / 10);
		_textA.setPosition((SCREEN_WIDTH / 2) - (_textA.getGlobalBounds().width / 2), _textA.getGlobalBounds().height / 2);
	}
	void LearnTextA::HandleInput()
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
	void LearnTextA::Update(float dt)
	{
	}
	void LearnTextA::Draw(float dt)
	{
		//clear / draw / display
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_malwareA);
		_data->window.draw(_textA);
		_data->window.draw(_backButton);

		_data->window.display();
	}
}