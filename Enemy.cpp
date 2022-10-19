#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = 5;	//rand() % 8 + 3; min = 3, max = 10
	this->type		 = 0;
	this->speed		 = -static_cast<float>(this->pointCount / 2);
	this->hpMax      = 15;   //static_cast<int>(this->pointCount);
	this->hp		 = this->hpMax;
	this->damage	 = 10;
	this->points	 = this->pointCount;
}

void Enemy::initShape()
{
	this->shape.setSize(sf::Vector2f(110.f, 98.f));
	this->shape.setScale(0.8f, 0.8f);

	//init Enemy GUI
	this->enemyHpBar.setSize(sf::Vector2f(200.f, 5.f));
	this->enemyHpBar.setFillColor(sf::Color::Red);
}

Enemy::Enemy(sf::Texture* texture, float pos_x,float pos_y)
{
	this->initVariables();
	this->initShape();
	this->shape.setTexture(texture);

	this->shape.setPosition(pos_x, pos_y);

	this->enemyHpBar.setPosition(sf::Vector2f(this->shape.getPosition().x + 10.f, this->shape.getPosition().y - 15.f));
}

Enemy::~Enemy()
{

}

const sf::Vector2f& Enemy::getpos() const
{
	return this->shape.getPosition();
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getHp() const
{
	return this->hp;
}

void Enemy::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Enemy::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->enemyHpBar.setSize(sf::Vector2f(60.f * hpPercent, this->enemyHpBar.getSize().y));
}

//func.
void Enemy::update()
{
	this->updateHpBar();
	this->shape.move(this->speed, 0.f);
	this->enemyHpBar.move(this->speed, 0.f);
	this->enemyHpBarBack.move(this->speed, 0.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->enemyHpBar);
}
