#pragma once

#include <memory>
#include <string>
#include<SFML/Graphics.hpp>
#include"StateMachine.hpp"
#include"AssetManager.hpp"
#include"InputManager.hpp"

namespace OCS
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};
	//used to access the classes in the GameData structure
	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		//constructor
		//parameters of screen dimensions and title on window
		//used in main.cpp
		Game(int width, int height, std::string title);

	private:
		//frame rate
		//60 fps
		const float dt = 1.0f / 60.f;
		sf::Clock _clock;

		//_data used to access all the game data above
		GameDataRef _data = std::make_shared<GameData>();

		//called when game start
		void Run();

	};
}