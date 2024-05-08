#include "Player.hpp"
#include <iostream>

namespace OCS
{
	Player::Player(GameDataRef data) : _data(data)
	{
		_data->assets.LoadTexture("Player Idle", PLAYER_FRAME_IDLE_FILEPATH);
		_data->assets.LoadTexture("Player Move", PLAYER_FRAME_MOVE_FILEPATH);

		_animationFrames.push_back(_data->assets.GetTexture("Player Idle"));
		_animationFrames.push_back(_data->assets.GetTexture("Player Move"));

		_playerSprite.setTexture(_animationFrames.at(_animationIterator));

		_playerSprite.setPosition((_data->window.getSize().x / 2) - (_playerSprite.getGlobalBounds().width / 2),
			(_data->window.getSize().y / 1.3) - (_playerSprite.getGlobalBounds().height / 2));
	}




	void Player::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			_playerSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
	}



	void Player::Input()
	{
		//sets x and y values
		float x = 0.0f;
		float y = 0.0f;

		//Pythagoras - Make diagonal movement same speed as horizontal and vertical movement
		x = std::sqrt(std::pow((double)x, 2) + std::pow((double)y, 2));
		y = std::sqrt(std::pow((double)x, 2) + std::pow((double)y, 2));

		//w decreases y value
		if (PLAYER_MOVEMENT_UP)
		{
			y -= PLAYER_MOVEMENT_SPEED;
		}
		//s increases y value
		else if (PLAYER_MOVEMENT_DOWN)
		{
			y += PLAYER_MOVEMENT_SPEED;
		}
		//a decreases x value
		if (PLAYER_MOVEMENT_LEFT)
		{
			x -= PLAYER_MOVEMENT_SPEED;
		}
		//d increases x value
		else if (PLAYER_MOVEMENT_RIGHT)
		{
			x += PLAYER_MOVEMENT_SPEED;
		}
		Update(x, y);
	}

	void Player::Update(const float dirX, const float dirY)
	{
		_playerSprite.move(PLAYER_MOVEMENT_SPEED * dirX, PLAYER_MOVEMENT_SPEED * dirY);

	}



	const sf::Sprite& Player::GetSprite() const
	{
		return _playerSprite;
	}

	void Player::Bounds()
	{
		//left collision
		if (_playerSprite.getGlobalBounds().left < 0.f)
			_playerSprite.setPosition(0.f, _playerSprite.getGlobalBounds().top);
		//right collision
		else if (_playerSprite.getGlobalBounds().left + _playerSprite.getGlobalBounds().width >= _data->window.getSize().x)
			_playerSprite.setPosition(_data->window.getSize().x - _playerSprite.getGlobalBounds().width, _playerSprite.getGlobalBounds().top);
		//top collision
		if (_playerSprite.getGlobalBounds().top < 0.f)
			_playerSprite.setPosition(_playerSprite.getGlobalBounds().left, 0.f);
		//bottom collision
		else if (_playerSprite.getGlobalBounds().top + _playerSprite.getGlobalBounds().height > _data->window.getSize().y)
			_playerSprite.setPosition(_playerSprite.getGlobalBounds().left, _data->window.getSize().y - _playerSprite.getGlobalBounds().height);
	}




	const sf::Vector2f& Player::getPos() const
	{
		return _playerSprite.getPosition();
	}

	void Player::Draw()
	{
		_data->window.draw(_playerSprite);


	}
}
	
