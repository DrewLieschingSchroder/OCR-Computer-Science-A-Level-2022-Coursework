#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace OCS
{
	class MovingBackground
	{
	public:
		//constructor
		MovingBackground(GameDataRef data);
		//functions
		void MoveBackground(float dt);
		void DrawBackground();
	private:
		//struct reference
		GameDataRef _data;
		//sprite
		std::vector<sf::Sprite>_movingBackgroundSprites;
		//frame rate
		float fps = 1000.f / 60.f;
	};
}
