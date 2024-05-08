#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace OCS
{
	class AssetManager
	{
	public:
		//constructor and destructor
		AssetManager() {}
		~AssetManager() {}

		//load texture method that takes 2 parameters
		void LoadTexture(std::string name, std::string fileName);
		//takes name of texture set with previous method and returns a reference
		sf::Texture& GetTexture(std::string name);

		//load font method that takes 2 parameters
		void LoadFont(std::string name, std::string fileName);
		//takes name of font set with previous method and returns a reference
		sf::Font& GetFont(std::string name);


	private:
		//maps
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	};
}