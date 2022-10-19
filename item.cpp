#include "item.h"

void Item::initVariables()
{
	this->speed = -static_cast<float>(2.f);
	this->heal = 5;
	this->hpMax = 15;
	this->hp = this->hpMax;

	this->preWidth = 2.f;
	this->preHeight = 2.f;
	this->width = 22.f;
	this->height = 22.f;
	this->flying = true;
	this->flyNum = 1;
}

void Item::initShape()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));

	//set texture to sprite
	this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->shape.setTexture(this->texture);
	this->shape.setTextureRect(this->currentFrame);


	//resize sprite
	this->shape.scale(1.f, 1.f);
}

void Item::initAnimation()
{
	this->animationTime.restart();
}

Item::Item(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();
	this->shape.setTexture(texture);

	this->shape.setPosition(pos_x, pos_y);
}

Item::~Item()
{
}

const sf::FloatRect Item::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Item::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
}

void Item::healHp(const int value)
{
	this->hp += value;
	if (this->hp < 0)
		this->hp = 0;
}

const int& Item::getHeal() const
{
	return this->heal;
}

void Item::updateAnimation()
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
			case 1: this->preWidth = 2.f,
					this->preHeight = 2.f,
					this->width = 22.f,
					this->height = 22.f;
				break;
			case 2: this->preWidth = 28.f,
					this->preHeight = 2.f,
					this->width = 31.f,
					this->height = 28.f;
				break;
			case 3:	this->preWidth = 61.f,
					this->preHeight = 2.f,
					this->width = 38.f,
					this->height = 35.f;
				break;
			case 4:	this->preWidth = 102.f,
					this->preHeight = 2.f,
					this->width = 48.f,
					this->height = 44.f;
				break;
			case 5:	this->preWidth = 158.f,
					this->preHeight = 4.f,
					this->width = 96.f,
					this->height = 86.f;
				break;
			}
			this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
			this->shape.setTextureRect(this->currentFrame);
			this->flyNum++;
		}
		this->animationTime.restart();
	}
}

void Item::update()
{
	this->shape.move(this->speed, 0.f);
	this->updateAnimation();
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
