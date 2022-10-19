#include "Boss.h"


void Boss::initVariables()
{
	this->pointCount = 50.f;
	this->type = 0;
	this->speed = -static_cast<float>(this->pointCount / 40);
	this->hpMax = 200;
	this->hp = this->hpMax;
	this->damage = 90;
	this->points = this->pointCount;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->preWidth = 4.f;
	this->preHeight = 3.f;
	this->width = 170.f;
	this->height = 162.f;
	this->flying = true;
	this->flyNum = 1;
}

void Boss::initShape()
{
	this->shape.setSize(sf::Vector2f(241.5f, 235.5f));

	//set texture to sprite
	this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->shape.setTexture(this->texture);
	this->shape.setTextureRect(this->currentFrame);

	//resize sprite
	this->shape.scale(1.f, 1.f);

	this->bossHpBar.setSize(sf::Vector2f(500.f, 50.f));
	this->bossHpBar.setFillColor(sf::Color::Blue);
}

void Boss::initAnimation()
{
	this->animationTime.restart();
}

void Boss::moveFollowUp(float dir_x, float dir_y)
{
	this->shape.move(0.f, -this->speed);
}

void Boss::moveFollowDown(float dir_x, float dir_y)
{
	this->shape.move(0.f, this->speed);
}

Boss::Boss(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();
	this->shape.setTexture(texture);

	this->shape.setPosition(pos_x, pos_y);

	this->bossHpBar.setPosition(140.f, 650.f);
}

Boss::~Boss()
{

}

const sf::Vector2f& Boss::getpos() const
{
	return this->shape.getPosition();
}

const sf::FloatRect Boss::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Boss::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
}

const int& Boss::getPoints() const
{
	return this->points;
}

const int& Boss::getDamage() const
{
	return this->damage;
}

const int& Boss::getHp() const
{
	return this->hp;
}

void Boss::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

const bool Boss::canAttack()
{
	int s = rand() % 200;
	if (s == 1)
	{
		this->attackCooldown = this->attackCooldownMax;
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Boss::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void Boss::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->bossHpBar.setSize(sf::Vector2f(1000.f * hpPercent, this->bossHpBar.getSize().y));
}

void Boss::updateAnimation()
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
			case 2: this->preWidth = 181.f;
				break;
			case 3:	this->preWidth = 534.f;
				break;
			case 4:	this->preWidth = 703.f;
				break;
			case 5:	this->preWidth = 881.f;
				break;
			}
			this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
			this->shape.setTextureRect(this->currentFrame);
			this->flyNum++;
		}
		this->animationTime.restart();
	}
}

void Boss::update()
{
	this->updateHpBar();
	if (this->shape.getPosition().x > 900)
	{
		this->shape.move(this->speed, 0.f);
	}

	this->updateAttack();
	this->updateAnimation();
}

void Boss::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->bossHpBar);
}