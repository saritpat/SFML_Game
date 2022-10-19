#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect currentFrame;
	sf::Clock animationTime;

	float movementSpeed;
	float width;
	float height;
	float preWidth;
	float preHeight;

	bool flying;
	int flyNum;

	float attackCooldown;
	float attackCooldownMax;

	float shotgunCooldown;
	float shotgunCooldownMax;

	int hp;
	int hpMax;

	//private func
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();

public:
	Player();
	virtual ~Player();

	//accessor
	const sf::Vector2f& getpos() const;
	sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	void healHp(const int value);

	//func
	void move(const float dirX, const float dirY);
	const bool canAttack();
	const bool shotgunAttack();

	void updateAttack();
	void updateShotgun();
	void updateAnimation();
	void update();
	
	void render(sf::RenderTarget& target);
};

