#pragma once

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace OCS
{
	class GUI
	{
	public:
		GUI(GameDataRef data);

		void Draw();
		void UpdateScore(unsigned int score);

	private:
		GameDataRef _data;

		//text
		sf::Text _scoreText;
	};
}