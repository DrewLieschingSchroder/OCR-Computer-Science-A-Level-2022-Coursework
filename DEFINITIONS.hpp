#pragma once
#include "Player.hpp"

//screen dimensions
#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 788

//splash state textures
#define SPLASH_STATE_BACKGROUND_FILEPATH "Texture/splashStateLogo.png"

//font
#define FONT_FILEPATH "Font/PressStart2P-Regular.ttf"

//music
#define MUSIC_MENU "Music/Danny Brown - Atrocity Exhibition - wav/Atrocity Exhibition-001-Danny Brown-Downward Spiral.wav"
#define MUSIC_GAME
#define MUSIC_GAME_OVER

//splash state time
#define SPLASH_STATE_SHOW_TIME 2.05f

//main menu state textures
#define GAME_TITLE_FILEPATH "Texture/gameTitle.png"
#define PLAY_BUTTON_FILEPATH "Texture/playButton.png"
#define MAIN_MENU_BG_FILEPATH "Texture/menuBackground.png"
#define OPTION_BUTTON_FILEPATH "Texture/Options.png"
#define LEARN_BUTTON_FILEPATH "Texture/Learn.png"

//learn state / option textures
#define LEARN_TEXT_FILEPATH "Texture/LearnText.png"
#define LEARN_TEXT_A_FILEPATH "Texture/text1.png"
#define LEARN_TEXT_B_FILEPATH "Texture/text2.png"
#define LEARN_TEXT_C_FILEPATH "Texture/text3.png"
#define LEARN_TEXT_D_FILEPATH "Texture/LearnText.png"
#define OPTIONS_CONTROL_FILEPATH "Texture/controls.png"

#define BACK_BUTTON_FILEPATH "Texture/BackButton.png"

#define OPTION_FILEPATH "Texture/easyMode.png"

//game state textures
#define GAME_STATE_BACKGROUND_FILEPATH "Texture/gameBackgroundINV2.png"
#define GAME_STATE_MOVING_BACKGROUND_FILEPATH "Texture/movingbg.png"

//game state values
#define BACKGROUND_MOVEMENT_SPEED 1000.f

//player texture
#define PLAYER_FRAME_IDLE_FILEPATH "Texture/player1.png"
#define PLAYER_FRAME_MOVE_FILEPATH "Texture/playerI.png"
#define PLAYER_ATTACK_FILEPATH "Texture/Attack.png"

#define PLAYER_ANIMATION 2.0f

//player movement
#define PLAYER_MOVEMENT_SPEED 2.0f
#define PLAYER_MOVEMENT_UP  sf::Keyboard::isKeyPressed(sf::Keyboard::W) xor sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
#define PLAYER_MOVEMENT_DOWN sf::Keyboard::isKeyPressed(sf::Keyboard::S) xor sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
#define PLAYER_MOVEMENT_LEFT sf::Keyboard::isKeyPressed(sf::Keyboard::A) xor sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
#define PLAYER_MOVEMENT_RIGHT sf::Keyboard::isKeyPressed(sf::Keyboard::D) xor sf::Keyboard::isKeyPressed(sf::Keyboard::Right)


//player attack
#define PLAYER_ATTACK_COOLDOWN_MAX 7.0f

//enemy 
#define ENEMY_A_FILEPATH "Texture/EnemyA.png"
#define ENEMY_B_FILEPATH "Texture/EnemyB.png"
#define ENEMY_C_FILEPATH "Texture/EnemyC.png"
#define ENEMY_D_FILEPATH "Texture/EnemyD.png"

#define ENEMY_AL_FILEPATH "Texture/EnemyAL.png"
#define ENEMY_BL_FILEPATH "Texture/EnemyBL.png"
#define ENEMY_CL_FILEPATH "Texture/EnemyCL.png"
#define ENEMY_DL_FILEPATH "Texture/EnemyDL.png"
#define ENEMY_D_SMALL_FILEPATH "Texture/EnemyDsmall.png"

#define SCORING_ENEMY_FILEPATH "Texture/gameBackgroundINV2.png"

#define ENEMY_MOVEMENT_SPEED 40.f
#define ENEMY_MOVEMENT_SPEED_2 70.f
#define ENEMY_MOVEMENT_SPEED_3 1.f

#define ENEMY_SPAWN_FREQUENCY_FAST 1.0f
#define ENEMY_SPAWN_FREQUENCY_SLOW 50.0f
#define ENEMY_SPAWN_FREQUENCY_MEDIUM 4.0f


//collision flash
#define FLASH_SPEED 1500.0f

//delay from when final life is used and game over appears
#define GAMEOVER_DELAY 1.5f

//game over state textures
#define GAMEOVER_STATE_BACKGROUND_FILEPATH "Texture/menuBackground.png"
#define GAMEOVER_STATE_TITLE_FILEPATH "Texture/gameOver.png"
#define GAMEOVER_STATE_BODY_FILEPATH "Texture/gameOverBody.png"
#define BRONZE_MEDAL_FILEPATH "Texture/medalBronze.png"
#define SILVER_MEDAL_FILEPATH "Texture/medalSilver.png"
#define GOLD_MEDAL_FILEPATH "Texture/medalGold.png"
#define DIAMOND_MEDAL_FILEPATH "Texture/medalPlatinum.png"

//medal scores
#define BRONZE_MEDAL_SCORE 5
#define SILVER_MEDAL_SCORE 10
#define GOLD_MEDAL_SCORE 15
#define DIAMOND_MEDAL_SCORE 20

//game states
enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};
