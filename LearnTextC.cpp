#include "LearnTextC.hpp"


namespace OCS
{
	LearnTextC::LearnTextC(GameDataRef data) : _data(data)
	{
	}
	void LearnTextC::Init()
	{
		//load textures
		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Malware C", ENEMY_C_FILEPATH);
		_data->assets.LoadTexture("Text C", LEARN_TEXT_C_FILEPATH);

		//set textures
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_malwareC.setTexture(this->_data->assets.GetTexture("Malware C"));
		_textC.setTexture(this->_data->assets.GetTexture("Text C"));

		//set position
		_backButton.setPosition((SCREEN_WIDTH / 2) - (_backButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.2) - (_backButton.getGlobalBounds().height / 2));
		_malwareC.setPosition((SCREEN_WIDTH / 2) - (_malwareC.getGlobalBounds().width / 2), _malwareC.getGlobalBounds().height / 10);
		_textC.setPosition((SCREEN_WIDTH / 2) - (_textC.getGlobalBounds().width / 2), _textC.getGlobalBounds().height / 2);
	}
	void LearnTextC::HandleInput()
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
	void LearnTextC::Update(float dt)
	{
	}
	void LearnTextC::Draw(float dt)
	{
		//clear / draw / display
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_malwareC);
		_data->window.draw(_textC);
		_data->window.draw(_backButton);

		_data->window.display();
	}
}