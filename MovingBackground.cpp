#include "MovingBackground.hpp"
#include "DEFINITIONS.hpp"

namespace OCS
{
	//constructor
	MovingBackground::MovingBackground(GameDataRef data) : _data(data)
	{
		//set texture to sprite
		_data->assets.LoadTexture("Moving Background", GAME_STATE_MOVING_BACKGROUND_FILEPATH);
		sf::Sprite sprite(_data->assets.GetTexture("Moving Background"));


		//set position
		sprite.setPosition(0, 0);


		//moves sprites
		_movingBackgroundSprites.push_back(sprite);

	}

	void MovingBackground::MoveBackground(float dt)
	{
		for (unsigned short int i = 0; i < _movingBackgroundSprites.size(); i++)
		{
			// movement = speed multiplied by delta time
			float movement = BACKGROUND_MOVEMENT_SPEED * dt;

			//direction
			_movingBackgroundSprites.at(i).move(0.0f, movement);
		}
	}

	void MovingBackground::DrawBackground()
	{
		for (unsigned short int i = 0; i < _movingBackgroundSprites.size(); i++)
		{
			//draw
			_data->window.draw(_movingBackgroundSprites.at(i));
		}
	}
}

