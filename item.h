#ifndef ITEM_H
#define ITEM_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>

class Item
{
private:
	sf::RectangleShape shape;
	sf::Texture* texture;
	sf::IntRect currentFrame;
	sf::Clock animationTime;
	
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	int heal;

	float width;
	float height;
	float preWidth;
	float preHeight;
	bool flying;
	int flyNum;

	void initVariables();
	void initShape();
	void initAnimation();

public:
	
	Item(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~Item();

	const sf::FloatRect getBounds() const;
	void setPosition(const float x, const float y);

	const int& getHeal() const;

	void healHp(const int value);

	void updateAnimation();
	void update();

	void render(sf::RenderTarget* target);
};
#endif //!ITEM_H
