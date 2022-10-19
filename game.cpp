#include "game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280,720), "GameR", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	//bullet
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Texture/bullet.png");

	//fireball
	this->textures["FIREBALL"] = new sf::Texture();
	this->textures["FIREBALL"]->loadFromFile("Texture/116747.png");

	//enemy
	this->babydragonTexture["ENEMY"] = new sf::Texture();
	this->babydragonTexture["ENEMY"]->loadFromFile("Texture/Baby Dragon1.png");

	//wyvern
	this->wyvernTexture["WYVERN"] = new sf::Texture();
	this->wyvernTexture["WYVERN"]->loadFromFile("Texture/Black Wizard Wyvern.png");

	//item
	this->itemTexture["ITEM"] = new sf::Texture();
	this->itemTexture["ITEM"]->loadFromFile("Texture/Health Item.png");

	//boss
	this->bossTexture["BOSS"] = new sf::Texture();
	this->bossTexture["BOSS"]->loadFromFile("Texture/Black Wyvern.png");

	//bg
	/*this->bgTextures["BG"] = new sf::Texture();
	this->bgTextures["BG"]->loadFromFile("Texture/realbackground.png");

	this->bgTextures2["BG"] = new sf::Texture();
	this->bgTextures2["BG"]->loadFromFile("Texture/realbackground.png");*/
}

void Game::initGUI()
{
	//load font
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	//Init point text
	this->pointText.setPosition(600, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::Black);

	//Init lives text
	this->pointText.setPosition(0.f, 50.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::Black);

	//init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(72);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setOutlineColor(sf::Color::Black);
	this->gameOverText.setOutlineThickness(1.5f);
	this->gameOverText.setString("	   Game Over!\nPress Enter to restart");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f, 
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f
								  );
	
	//init Player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Green);
	this->playerHpBar.setPosition(10.f, 20.f);

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color::Red);
}

void Game::initWorld()
{
	//B sky
	if (!this->worldBackgroundTexture1_1.loadFromFile("Texture/nameb.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	
	//C sky
	if (!this->worldBackgroundTexture1_2.loadFromFile("Texture/realbackground1.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture1" << "\n";
	}
	this->worldBackground1.setTexture(this->worldBackgroundTexture1_1);
	this->worldBackground1.setScale(2.f, 2.f);

	//B sky
	if (!this->worldBackgroundTexture2_1.loadFromFile("Texture/nameb.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}

	//C sky
	if (!this->worldBackgroundTexture2_2.loadFromFile("Texture/realbackground1.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture1" << "\n";
	}
	this->worldBackground2.setTexture(this->worldBackgroundTexture2_1);
	this->worldBackground2.setScale(1.7f, 1.7f);
	this->worldBackground2.setPosition(100.f, 0.f);
}

void Game::initSystem()
{
	this->points = 0;
	this->lives = 70;
}

void Game::initSound()
{
	//background
	this->bgBuffer.loadFromFile("Sound/HGW_Airplane_alt_v2b (online-audio-converter.com).wav");
	this->bgSound.setBuffer(bgBuffer);
	this->bgSound.setVolume(2);
	this->bgSound.play();
	this->bgSound.setLoop(true);

	//die
	this->dieBuffer.loadFromFile("Sound/E die.wav");
	this->dieEffect.setBuffer(dieBuffer);
	this->dieEffect.setVolume(10);

	//heal
	this->healBuffer.loadFromFile("Sound/heal.wav");
	this->healEffect.setBuffer(healBuffer);
	this->healEffect.setVolume(10);

	//gun
	this->gunBuffer.loadFromFile("Sound/gun-shot.wav");
	this->gunEffect.setBuffer(gunBuffer);
	this->gunEffect.setVolume(4);

	//pushfire
	this->fireBuffer.loadFromFile("Sound/big-fire.wav");
	this->fireEffect.setBuffer(fireBuffer);
	this->fireEffect.setVolume(5);
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	//baby
	this->spawnTimerMax = 150.f;
	this->spawnTimer = this->spawnTimerMax;

	//wyvern
	this->wyvernSpawnTimerMax = 450.f;
	this->wyvernSpawnTimer = 0.f;

	//boss
	this->bossSpawnTimerMax = 4000.f;
	this->bossSpawnTimer = this->spawnTimerMax;
}

void Game::initItem()
{

}

//con 
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initSound();

	this->initPlayer();
	this->initEnemies();
	this->initItem();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//del textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}
	for (auto& i : this->fireTextures)
	{
		delete i.second;
	}
	for (auto& i : this->babydragonTexture)
	{
		delete i.second;
	}
	for (auto& i : this->wyvernTexture)
	{
		delete i.second;
	}
	for (auto& i : this->itemTexture)
	{
		delete i.second;
	}
	for (auto& i : this->bossTexture)
	{
		delete i.second;
	}

	//del bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}

	//del fires
	for (auto* i : this->fireBalls)
	{
		delete i;
	}

	//del enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}

	//del wyvern
	for (auto* i : this->wyverns)
	{
		delete i;
	}

	//del item
	for (auto* i : this->items)
	{
		delete i;
	}

	//del boss
	for (auto* i : this->bosses)
	{
		delete i;
	}
}

//func
void Game::run()
{
	while (this->window->isOpen())
	{
		this->player->setPosition(0.f, 0.f);
		this->player->setHp(100);
		this->enemies.clear();
		this->wyverns.clear();
		this->bosses.clear();
		this->bullets.clear();
		this->fireBalls.clear();

		sf::Event e;
		while (true)
		{
			std::cout << "  state 2 \n";
			while (this->window->pollEvent(e))
			{
				if (e.Event::type == sf::Event::Closed)
					this->window->close();
			}
			if (this->player->getHp() > 0)
			{
				this->update();
				this->render();
			}
			else
			{
				break;
			}
		}
		break;
	}
}

void Game::updatePollEvent()
{

}

void Game::updateInput()
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getpos().x + 150.f, this->player->getpos().y + 60.f, 1.f, 0.f, 7.f));
		this->gunEffect.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->shotgunAttack() && this->player->getHp() == this->player->getHpMax())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getpos().x + 150.f, this->player->getpos().y + 60.f, 1.f, -1.f, 3.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getpos().x + 150.f, this->player->getpos().y + 60.f, 1.f, 1.f, 3.f));
		this->gunEffect.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		this->player->setHp(0);
	}
}

void Game::updateGUI()
{
	std::stringstream ss;

	ss << "Points : " << this->points;

	this->pointText.setString(ss.str());

	//update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateWorld()
{
	this->worldBackground1.move(-0.05f, 0.f);
	if (this->points >= 200)
	{
		this->worldBackground1.setTexture(this->worldBackgroundTexture1_1);
		this->spawnTimerMax = 75.f;
		this->wyvernSpawnTimerMax = 400.f;
	}

	if (this->points >= 400)
	{
		this->worldBackground1.setTexture(this->worldBackgroundTexture1_2);
		this->spawnTimerMax = 25.f;
		this->wyvernSpawnTimerMax = 200.f;
		this->bossSpawnTimerMax = 3000.f;
	}
}

void Game::updateCollision()
{
	////////////////////////  P  L  A  Y  E  R////////////////////////////////
	//left world collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	//right world collision
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	//top up world collision
	if (this->player->getBounds().top < -15.f)
	{
		this->player->setPosition(this->player->getBounds().left, -15.f);
	}

	//bottom world collision
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}

	/////////////////////////W  Y  V  E  R  N//////////////////////////////
	for (int i = 0; i < this->wyverns.size(); ++i)
	{
		//top up world collision
		if (this->wyverns[i]->getBounds().top < -15.f)
		{
			this->wyverns[i]->setPosition(this->wyverns[i]->getBounds().left, -15.f);
		}

		//bottom world collision
		else if (this->wyverns[i]->getBounds().top + this->wyverns[i]->getBounds().height >= this->window->getSize().y)
		{
			this->wyverns[i]->setPosition(this->wyverns[i]->getBounds().left, this->window->getSize().y - this->wyverns[i]->getBounds().height);
		}
	}
	/////////////////////////B  O  S  S //////////////////////////////
	for (int i = 0; i < this->bosses.size(); ++i)
	{
		//top up world collision
		if (this->bosses[i]->getBounds().top < -100.f)
		{
			this->bosses[i]->setPosition(this->bosses[i]->getBounds().left, -100.f);
		}

		//bottom world collision
		else if (this->bosses[i]->getBounds().top + this->bosses[i]->getBounds().height >= this->window->getSize().y)
		{
			this->bosses[i]->setPosition(this->bosses[i]->getBounds().left, this->window->getSize().y - this->bosses[i]->getBounds().height);
		}
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets)
	{
		bullet->update();

		//bullet culling
		if (bullet->getBounds().left > this->window->getSize().x)
		{
			//del bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateFireBalls()
{
	unsigned counterF = 0;
	for (auto* fireBall : this->fireBalls)
	{
		fireBall->update();

		//fireball culling
		if (fireBall->getBounds().left > this->window->getSize().x)
		{
			//del fireball
			delete this->fireBalls.at(counterF);
			this->fireBalls.erase(this->fireBalls.begin() + counterF);
			--counterF;
		}
		++counterF;
	}
		
}

void Game::updateEnemies()
{
	//spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(this->babydragonTexture["ENEMY"], this->window->getSize().x, rand() % 512));//min = 98.f max = 698.f this->window->getSize().y - 98.f
		this->spawnTimer = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//enemies culling (left of the screen)
		if (enemy->getBounds().left < -110.f)
		{
			//del enemies
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
			lives--;
		}

		//enemies culling (player)
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->dieEffect.play();
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		++counter;
	}

	//spawning
	this->wyvernSpawnTimer += 0.5f;
	if (this->wyvernSpawnTimer >= this->wyvernSpawnTimerMax)
	{
		this->wyverns.push_back(new Wyvern(this->wyvernTexture["WYVERN"], this->window->getSize().x, rand() % 512));
		this->wyvernSpawnTimer = 0.f;
	}

	//update
	unsigned counterW = 0;
	for (auto* wyvern : this->wyverns)
	{
		wyvern->update();

		//wyverns culling (left of the screen)
		if (wyvern->getBounds().left < -161.f)
		{
			//del wyverns
			delete this->wyverns.at(counterW);
			this->wyverns.erase(this->wyverns.begin() + counterW);
			--counterW;
			lives--;
		}

		//wyverns culling (player)
		else if (wyvern->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->wyverns.at(counterW)->getDamage());
			delete this->wyverns.at(counterW);
			this->dieEffect.play();
			this->wyverns.erase(this->wyverns.begin() + counterW);
			--counterW;
		}

		++counterW;
	}

	//spawning
	this->bossSpawnTimer += 0.5f;
	if (this->bossSpawnTimer >= this->bossSpawnTimerMax)
	{
		this->bosses.push_back(new Boss(this->bossTexture["BOSS"], this->window->getSize().x, this->window->getSize().y / 2 - 235.5f));
		this->bossSpawnTimer = 0.f;
	}

	//update
	unsigned counterB = 0;
	for (auto* boss : this->bosses)
	{
		boss->update();
		
		if (boss->getpos().y < this->player->getpos().y - 100.f)
		{
			boss->moveFollowUp(0.f, 50.f / 40.f);
		}
		if (boss->getpos().y > this->player->getpos().y - 100.f)
		{
			boss->moveFollowDown(0.f, 50.f / 40.f);
		}
		

		//bosses culling (left of the screen)
		if (boss->getBounds().left < -161.f)
		{
			//del bosses
			delete this->bosses.at(counterB);
			this->bosses.erase(this->bosses.begin() + counterB);
			--counterB;
			lives--;
		}

		//bosses culling (player)
		else if (boss->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->bosses.at(counterB)->getDamage());
			delete this->bosses.at(counterB);
			this->dieEffect.play();
			this->bosses.erase(this->bosses.begin() + counterB);
			--counterB;
		}

		++counterB;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{	
			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->enemies[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->enemies[i]->getHp() == 0)
				{
					this->points += 2;
					enemy_deleted = true;
					this->dieEffect.play();
					std::cout << "point " << this->points << "\n";
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}

	for (size_t l = 0; l < this->fireBalls.size(); l++)
	{
		if (this->fireBalls[l]->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->fireBalls[l]->getDamage());
			this->fireBalls.erase(this->fireBalls.begin() + l);
		}
	}
}

void Game::updateWyvernCombat()
{
	for (int i = 0; i < this->wyverns.size(); ++i)
	{
		bool wyvern_deleted = false;
		if (this->wyverns[i]->canAttack())
		{
			this->fireBalls.push_back(new FireBall(this->textures["FIREBALL"], this->wyverns[i]->getpos().x - 70.f, this->wyverns[i]->getpos().y + 100.f, -1.f, 0.f, -3.f));
			this->fireEffect.play();
		}
		for (size_t k = 0; k < this->bullets.size() && wyvern_deleted == false; k++)
		{
			if (this->bullets[k]->getBounds().intersects(this->wyverns[i]->getBounds()))
			{
				this->wyverns[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->wyverns[i]->getHp() == 0)
				{
					this->points += 5;
					int S = rand() % 4;
					if (S == 0)
					{
						this->items.push_back(new Item(this->itemTexture["ITEM"], this->wyverns[i]->getpos().x + 10.f, this->wyverns[i]->getpos().y + 20.f));
					}
					wyvern_deleted = true;
					this->dieEffect.play();
					std::cout << "point " << this->points << "\n";
					this->wyverns.erase(this->wyverns.begin() + i);
				}
			}
		}
	}
}

void Game::updateBossCombat()
{
	for (int i = 0; i < this->bosses.size(); ++i)
	{
		bool boss_deleted = false;
		if (this->bosses[i]->canAttack())
		{
			this->fireBalls.push_back(new FireBall(this->textures["FIREBALL"], this->bosses[i]->getpos().x - 70.f, this->bosses[i]->getpos().y + 150.f, -1.f, 0.f, -3.f));
			this->fireEffect.play();
		}
		for (size_t k = 0; k < this->bullets.size() && boss_deleted == false; k++)
		{
			if (this->bullets[k]->getBounds().intersects(this->bosses[i]->getBounds()))
			{
				this->bosses[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->bosses[i]->getHp() == 0)
				{
					this->points += 20;
					int S = 0;
					if (S == 0)
					{
						this->items.push_back(new Item(this->itemTexture["ITEM"], this->bosses[i]->getpos().x + 10.f, this->bosses[i]->getpos().y + 20.f));
						this->items.push_back(new Item(this->itemTexture["ITEM"], this->bosses[i]->getpos().x + 10.f, this->bosses[i]->getpos().y + 20.f));
					}
					boss_deleted = true;
					this->dieEffect.play();
					std::cout << "point " << this->points << "\n";
					this->bosses.erase(this->bosses.begin() + i);
				}
			}
		}
	}
}

void Game::updateSound()
{

}

void Game::updateItem()
{
	unsigned counterI = 0;
	for (auto* item : this->items)
	{
		item->update();
		//items culling (left of the screen)
		if (item->getBounds().left < 0.f)
		{
			//del items
			delete this->items.at(counterI);
			this->items.erase(this->items.begin() + counterI);
			--counterI;
		}

		//items culling (player)
		else if (item->getBounds().intersects(this->player->getBounds()))
		{
			this->player->healHp(this->items.at(counterI)->getHeal());
			delete this->items.at(counterI);
			this->healEffect.play();
			this->items.erase(this->items.begin() + counterI);
			--counterI;
		}

		++counterI;
	}
}

void Game::update()
{
	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateBullets();

	this->updateFireBalls();

	this->updateEnemies();

	this->updateCombat();

	this->updateWyvernCombat();

	this->updateBossCombat();

	this->updateSound();

	this->updateItem();

	this->updateGUI();

	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);

	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground1);
}

void Game::render()
{
	this->window->clear();

	//draw world
	this->renderWorld();

	//draw all stuffs
	this->player->render(*this->window);
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* fireBall : this->fireBalls)
	{
		fireBall->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* item : this->items)
	{
		item->render(this->window);
	}

	for (auto* wyvern : this->wyverns)
	{
		wyvern->render(this->window);
	}

	for (auto* boss : this->bosses)
	{
		boss->render(this->window);
	}

	for (auto* item : this->items)
	{
		item->render(this->window);
	}

	this->renderGUI();

	
	//game over screen
	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
	}

	this->window->display();
}

int Game::getScore()
{
	return this->points;
}
