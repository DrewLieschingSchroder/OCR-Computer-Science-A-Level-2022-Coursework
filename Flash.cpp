#include "Flash.hpp"

namespace OCS
{
	Flash::Flash(GameDataRef data) : _data(data)
	{
		//flash sprite and size
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		_shape.setFillColor(sf::Color(255, 255, 255, 0));

		//flash set to true
		_flashOn = true;
	}

	void Flash::Show(float dt)
	{
		if (_flashOn)
		{
			//flash red
			int _flash = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);

			//set flash to false
			if (_flash >= 9600.0f)
			{
				_flash = 96.0f;
				_flashOn = false;
			}
			//red flash
			_shape.setFillColor(sf::Color(255, 0, 0, _flash));
		}
		else
		{
			//flash white
			int _flash = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);

			//set flash to false
			if (_flash <= 0.0f)
			{
				_flash = 0.0f;
				_flashOn = false;
			}
			//white flash
			_shape.setFillColor(sf::Color(255, 255, 255, _flash));
		}
	}
	void Flash::Draw()
	{
		_data->window.draw(_shape);
	}
}
