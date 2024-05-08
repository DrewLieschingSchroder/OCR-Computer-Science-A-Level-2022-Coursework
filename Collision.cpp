#include "Collision.hpp"

namespace OCS
{
	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		//returns rectangles around the sprites
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		//if sprite 1 intersects sprite 2 true is returned
		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
	{
		//set scale of rectangles around sprite
		sprite1.setScale(scale1, scale1);
		sprite2.setScale(scale2, scale2);

		//returns rectangles around the sprites
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		//if sprite 1 intersects sprite 2 true is returned
		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}