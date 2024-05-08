#include "AssetManager.hpp"

namespace OCS
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		//local texture variable
		sf::Texture tex;

		//if the texture loads from file
		if (tex.loadFromFile(fileName))
		{
			//it is added to texture map
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		//returns textures based on name previously given to texture
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		//local font variable
		sf::Font font;

		//if the font loads from file
		if (font.loadFromFile(fileName))
		{
			//it is added to font map
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		//returns font based on name previously given to font
		return this->_fonts.at(name);
	}


}