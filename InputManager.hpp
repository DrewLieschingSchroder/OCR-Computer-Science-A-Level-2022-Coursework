#pragma once

#include <SFML/Graphics.hpp>

namespace OCS
{
	class InputManager
	{
	public:
		//constructor and destructor
		InputManager() {}
		~InputManager() {}

		//boolean statement 
		//checks if a sprite is left clicked with mouse
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		//get mouse position function
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);

	};
}
