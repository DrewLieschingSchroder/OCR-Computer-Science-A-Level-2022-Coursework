#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/Audio.hpp>

//main
int main()
{
	//OCS is the namespace used through out
	//contains definitions of the window dimensions and has window title
	OCS::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "OPERATION: CYBER_SECURITY");

	return EXIT_SUCCESS;
}