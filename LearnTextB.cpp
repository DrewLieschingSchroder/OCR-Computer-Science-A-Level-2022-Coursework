#include "LearnTextB.hpp"


namespace OCS
{
	LearnTextB::LearnTextB(GameDataRef data) : _data(data)
	{
	}
	void LearnTextB::Init()
	{
		//load textures
		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Malware B", ENEMY_B_FILEPATH);
		_data->assets.LoadTexture("Text B", LEARN_TEXT_B_FILEPATH);

		//set textures
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_malwareB.setTexture(this->_data->assets.GetTexture("Malware B"));
		_textB.setTexture(this->_data->assets.GetTexture("Text B"));

		//set position
		_backButton.setPosition((SCREEN_WIDTH / 2) - (_backButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_backButton.getGlobalBounds().height / 2));
		_malwareB.setPosition((SCREEN_WIDTH / 2) - (_malwareB.getGlobalBounds().width / 2), _malwareB.getGlobalBounds().height / 10);
		_textB.setPosition((SCREEN_WIDTH / 2) - (_textB.getGlobalBounds().width / 2), _textB.getGlobalBounds().height / 2);
	}
	void LearnTextB::HandleInput()
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
	void LearnTextB::Update(float dt)
	{
	}
	void LearnTextB::Draw(float dt)
	{
		//clear / draw / display
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_malwareB);
		_data->window.draw(_textB);
		_data->window.draw(_backButton);

		_data->window.display();
	}
}