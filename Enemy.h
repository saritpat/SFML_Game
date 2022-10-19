#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>

class Enemy
{
private:
	unsigned pointCount;

	sf::RectangleShape shape;
	sf::Texture* texture;

	//enemyGUI
	sf::RectangleShape enemyHpBar;
	sf::RectangleShape enemyHpBarBack;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initVariables();
	void initShape();
	
public:
	Enemy(sf::Texture*texture, float pos_x, float pos_y);
	virtual ~Enemy();

	//accessor
	const sf::Vector2f& getpos() const;
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//modifier
	const int& getHp() const;
	void loseHp(const int value);

	//func
	void updateHpBar();
	void update();
	void render(sf::RenderTarget* target);
};
#endif //!ENEMY_H

