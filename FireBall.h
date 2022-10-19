#ifndef FIREBALL_H
#define FIREBALL_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>

class FireBall
{
private:
	sf::Sprite shape;
	sf::Texture* texture;
	sf::Vector2f direction;
	sf::IntRect currentFrame;
	sf::Clock animationTime;

	float movementSpeed;
	int damage;

	float width;
	float height;
	float preWidth;
	float preHeight;
	bool flying;
	int flyNum;

	void initVariables();
	void initAnimation();

public:

	FireBall(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~FireBall();

	//accessor
	const sf::FloatRect getBounds() const;
	const int& getDamage() const;

	void updateAnimation();
	void update();
	void render(sf::RenderTarget* target);

};
#endif //!FIREBALL_H
