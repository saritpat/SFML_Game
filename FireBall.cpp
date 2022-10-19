#include "FireBall.h"

void FireBall::initVariables()
{
	this->damage = 10;

	this->preWidth = 0.f;
	this->preHeight = 3.f;
	this->width = 16.f;
	this->height = 9.f;
	this->flying = true;
	this->flyNum = 1;
}

void FireBall::initAnimation()
{
	this->animationTime.restart();
}

FireBall::FireBall(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->initVariables();

	this->shape.setTexture(*texture);
	this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->shape.setTextureRect(this->currentFrame);
	this->shape.scale(5.f, 5.f);

	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

FireBall::~FireBall()
{

}

const sf::FloatRect FireBall::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& FireBall::getDamage() const
{
	return this->damage;
}

void FireBall::updateAnimation()
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
			case 1: this->preHeight = 3.f;
				break;		 
			case 2: this->preHeight = 20.f;
				break;		 
			case 3:	this->preHeight = 35.f;
				break;		 
			case 4:	this->preHeight = 51.f;
				break;		 
			case 5:	this->preHeight = 67.f;
				break;
			}
			this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
			this->shape.setTextureRect(this->currentFrame);
			this->flyNum++;
		}
		this->animationTime.restart();
	}
}

void FireBall::update()
{
	//move
	this->shape.move(this->movementSpeed, 0.f);
	this->updateAnimation();
}

void FireBall::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
