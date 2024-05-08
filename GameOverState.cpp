#include <iostream>
#include "GameOverState.hpp"

namespace OCS
{
	//constructor
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
	{
	}
	//initialiser
	void GameOverState::Init()
	{
		//will read from respective text file
		std::ifstream readFile;
		readFile.open("TextFile/Highscores.txt");

		if (readFile.is_open())
		{
			//reads whole file and set that value as high score
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}
		//closes file
		readFile.close();
		//write to highscore text file
		std::ofstream writeFile("TextFile/Highscores.txt");

		if (writeFile.is_open())
		{
			//if the score of current run is higher than high score
			if (_score > _highScore)
			{
				//highscore become score value
				_highScore = _score;
			}
			//new score is written into high score file
			writeFile << _highScore;
		}
		//closes the file
		writeFile.close();
		//loads textures from DEFINITION file
		_data->assets.LoadTexture("Game Over State Background", GAMEOVER_STATE_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Over State Title", GAMEOVER_STATE_TITLE_FILEPATH);
		_data->assets.LoadTexture("Game Over State Body", GAMEOVER_STATE_BODY_FILEPATH);
		_data->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
		_data->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
		_data->assets.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
		_data->assets.LoadTexture("Diamond Medal", DIAMOND_MEDAL_FILEPATH);
		//set textures to sprites
		_background.setTexture(this->_data->assets.GetTexture("Game Over State Background"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over State Title"));
		_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over State Body"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		//set positions of sprites
		_gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2),
			(_data->window.getSize().y / 1.9) - (_gameOverContainer.getGlobalBounds().height / 2));
		_gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2),
			_gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.08));
		_retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2),
			_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.08));
		//set values to the score text text
		_scoreText.setFont(_data->assets.GetFont("Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(32);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 6.35, _data->window.getSize().y / 2.0f);
		//set values to the high score text text
		_highScoreText.setFont(_data->assets.GetFont("Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(32);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 6.35, _data->window.getSize().y / 1.6f);
		//medal if statements
		//score will find the highest medal it can be assigned, this becomes the awarded medal
		if (_score >= DIAMOND_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Diamond Medal"));
		}
		else if (_score >= GOLD_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Gold Medal"));
		}
		else if (_score >= SILVER_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Silver Medal"));
		}
		else if (_score >= BRONZE_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Bronze Medal"));
		}
		_medal.setPosition(477, 370);
	}
	
	void GameOverState::HandleInput()
	{
		//event loop
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			//closes window if close is clicked
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			//if retry button is pressed, user is taken menu state
			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{
	}

	void GameOverState::Draw(float dt)
	{
		//draw sprites to screen
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);
		_data->window.draw(_medal);
		//display function
		_data->window.display();
	}
}