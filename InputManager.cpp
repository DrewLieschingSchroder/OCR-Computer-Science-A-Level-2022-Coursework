#include "InputManager.hpp"

namespace OCS
{

	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			//creates rectangle covering the given object sprite
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			//if mouse is inside the rectangle boolean statement returns true
			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		//else returns false
		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		//return the poisiton of mouse relative to window
		return sf::Mouse::getPosition(window);
	}
}