#pragma once

#include "Attack.hpp"
#include "Game.hpp"


namespace OCS
{
	class PlayerAttack : public Attack
	{
	public:
		//constructor - texture, x and y position, x and y direction, bullet movement speed
		PlayerAttack(GameDataRef data) : _data(data)
		{
		}

		void update()
		{
			
		}
		void Draw()
		{
			
		}

		

		

		

	private:
		GameDataRef _data;
		
		
	};
}