#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<stack>
#include<utility>
#include<fstream>
#include<algorithm>

#include "player.h"
#include "bullet.h"
#include "Enemy.h"
#include "Wyvern.h"
#include "item.h"
#include "Boss.h"
#include "FireBall.h"
#include "Background.h"
#include"State.h"
#include"GameState.h"


class Game
{
private:
	std::stack<State*> states;
	//window
	sf::RenderWindow* window;

	//Resource bullets
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//Resource fireBalls
	std::map<std::string, sf::Texture*> fireTextures;
	std::vector<FireBall*> fireBalls;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	sf::Text liveText;
	//world
	sf::Texture worldBackgroundTexture1_1;
	sf::Sprite worldBackground1;
	sf::Texture worldBackgroundTexture1_2;


	sf::Texture worldBackgroundTexture2_1;
	sf::Sprite worldBackground2;
	sf::Texture worldBackgroundTexture2_2;


	//player
	Player* player;

	//playerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//enemies
	float spawnTimer;
	float spawnTimerMax;
	std::map<std::string, sf::Texture*> babydragonTexture;
	std::vector<Enemy*> enemies;

	//wyvern
	float wyvernSpawnTimer;
	float wyvernSpawnTimerMax;
	std::map<std::string, sf::Texture*> wyvernTexture;
	std::vector<Wyvern*> wyverns;
	
	//item
	float itemSpawnTimer;
	float itemSpawnTimerMax;
	std::map<std::string, sf::Texture*> itemTexture;
	std::vector<Item*> items;

	//boss
	float bossSpawnTimer;
	float bossSpawnTimerMax;
	std::map<std::string, sf::Texture*> bossTexture;
	std::vector<Boss*> bosses;

	//sound
	sf::SoundBuffer gunBuffer;
	sf::Sound gunEffect;

	sf::SoundBuffer fireBuffer;
	sf::Sound fireEffect;

	sf::SoundBuffer bgBuffer;
	sf::Sound bgSound;

	sf::SoundBuffer dieBuffer;
	sf::Sound dieEffect;

	sf::SoundBuffer healBuffer;
	sf::Sound healEffect;



	//private func
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystem();
	void initSound();

	void initPlayer();
	void initEnemies();
	void initItem();
	

public:

	//system
	int points;
	int lives;
	Game();
	virtual ~Game();

	void run();

	//maingame
	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateFireBalls();
	void updateEnemies();
	void updateCombat();
	void updateWyvernCombat();
	void updateBossCombat();
	void updateSound();
	void updateItem();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
	int getScore();
};

