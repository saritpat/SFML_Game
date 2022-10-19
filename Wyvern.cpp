#include "Wyvern.h"

void Wyvern::initVariables()
{
	this->pointCount = 5.f;	//rand() % 8 + 3; min = 3, max = 10
	this->type		 = 0;
	this->speed		 = -static_cast<float>(this->pointCount / 4);
	this->hpMax		 = 25;   
	this->hp		 = this->hpMax;
	this->damage	 = 10;
	this->points	 = this->pointCount;

	this->preWidth = 4.f;
	this->preHeight = 7.f;
	this->width = 174.f;
	this->height = 150.f;
	this->flying = true;
	this->flyNum = 1;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Wyvern::initShape()
{
	this->shape.setSize(sf::Vector2f(174.f, 150.f));

	//set texture to sprite
	this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->shape.setTexture(this->texture);
	this->shape.setTextureRect(this->currentFrame);

	//resize sprite
	this->shape.scale(1.f, 1.f);

	this->enemyHpBar.setSize(sf::Vector2f(200.f, 5.f));
	this->enemyHpBar.setFillColor(sf::Color::Red);
}

void Wyvern::initAnimation()
{
	this->animationTime.restart();
}

Wyvern::Wyvern(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();
	this->shape.setTexture(texture);

	this->shape.setPosition(pos_x, pos_y);

	this->enemyHpBar.setPosition(sf::Vector2f(this->shape.getPosition().x + 30.f, this->shape.getPosition().y - 15.f));
}

Wyvern::~Wyvern()
{

}

const sf::Vector2f& Wyvern::getpos() const
{
	return this->shape.getPosition();
}

const sf::FloatRect Wyvern::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Wyvern::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
}

const int& Wyvern::getPoints() const
{
	return this->points;
}

const int& Wyvern::getDamage() const
{
	return this->damage;
}

const int& Wyvern::getHp() const
{
	return this->hp;
}

void Wyvern::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

const bool Wyvern::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Wyvern::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.04f;
	}
}

void Wyvern::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->enemyHpBar.setSize(sf::Vector2f(60.f * hpPercent, this->enemyHpBar.getSize().y));
}

void Wyvern::updateAnimation()
{
	if (this->animationTime.getElapsedTime().asSeconds() >= 0.125f)
	{
		if (this->flyNum >= 6)
		{
			this->flyNum = 1;
		}
		if (this->flying == true)
		{
			switch (this->flyNum)
			{
			case 1: this->preWidth = 4.f;
				break;
			case 2: this->preWidth  = 180.f,
					this->preHeight = 23.f;
				break;
			case 3:	this->preWidth  = 506.f,
					this->preHeight = 26.f;
				break;
			case 4:	this->preWidth  = 678.f,
					this->preHeight = 25.f;
				break;
			case 5:	this->preWidth  = 850.f,
					this->preHeight = 20.f;
				break;
			}
			this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
			this->shape.setTextureRect(this->currentFrame);
			this->flyNum++;
		}
		this->animationTime.restart();
	}
}

void Wyvern::update()
{
	this->updateHpBar();
	this->shape.move(this->speed, 0.f);
	this->enemyHpBar.move(this->speed, 0.f);
	this->enemyHpBarBack.move(this->speed, 0.f);
	this->updateAttack();
	this->updateAnimation();
}

void Wyvern::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->enemyHpBar);
}
