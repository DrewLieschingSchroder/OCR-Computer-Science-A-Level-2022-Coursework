#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>



namespace OCS
{
	class Player
	{
	public:
		Player(GameDataRef data);

		void Animate(float dt);

		void Input();

		void Update(const float dirX, const float dirY);

		const sf::Sprite& GetSprite() const;

		void Bounds();

		const sf::Vector2f& getPos() const;

		void Draw();

	private:
		GameDataRef _data;

		sf::Sprite _playerSprite;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator;

		sf::Clock _clock;

		sf::Clock _movementClock;

		int _playerState;
	};

	class AttackInit
	{
	public:
		AttackInit(GameDataRef data);

		void UpdateAttackMove();




		void Draw();
	private:

		GameDataRef _data;
	

	};
}