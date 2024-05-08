#include "GUI.hpp"

#include <string>

namespace OCS
{
	//constructor
	GUI::GUI(GameDataRef data) : _data(data)
	{
		//calls font from DEFINITIONS
		_data->assets.LoadFont("Font", FONT_FILEPATH);

		//text style
		_scoreText.setFont(_data->assets.GetFont("Font"));
		_scoreText.setString("0");
		_scoreText.setCharacterSize(65);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 10);
	}

	void GUI::Draw()
	{
		//draw function
		_data->window.draw(_scoreText);
	}

	void GUI::UpdateScore(unsigned int score)
	{
		//update function
		_scoreText.setString(std::to_string(score));
	}
}