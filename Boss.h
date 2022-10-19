#ifndef BOSS_H
#define BOSS_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>

class Boss
{
private:
	unsigned pointCount;

	sf::RectangleShape shape;
	sf::Vector2f direction;
	sf::Texture* texture;
	sf::IntRect currentFrame;
	sf::Clock animationTime;

	//enemyGUI
	sf::RectangleShape bossHpBar;
	sf::RectangleShape bossHpBarBack;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	float width;
	float height;
	float preWidth;
	float preHeight;
	bool flying;
	int flyNum;

	float attackCooldown;
	float attackCooldownMax;

	void initVariables();
	void initShape();
	void initAnimation();
	

public:
	Boss(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~Boss();

	//accessor
	const sf::Vector2f& getpos() const;
	const sf::FloatRect getBounds() const;
	void setPosition(const float x, const float y);
	const int& getPoints() const;
	const int& getDamage() const;

	//modifier
	const int& getHp() const;
	void loseHp(const int value);
	void moveFollowUp(float dir_x, float dir_y);
	void moveFollowDown(float dir_x, float dir_y);

	//func
	const bool canAttack();

	void updateAttack();
	void updateHpBar();
	void updateAnimation();
	void update();

	void render(sf::RenderTarget* target);
};
#endif //!BOSS_H

