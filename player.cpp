#include "player.h"

void Player::initVariables()
{
	this->movementSpeed = 4.f;
	this->preWidth = 4.f;
	this->preHeight = 0.f;
	this->width = 200.f;
	this->height = 80.f;

	this->flying = true;
	this->flyNum = 1;

	this->attackCooldownMax = 10.f;
	this->attackCooldown	= this->attackCooldownMax;

	this->shotgunCooldownMax = 100.f;
	this->shotgunCooldown	 = this->shotgunCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;

}

void Player::initTexture()
{
	//loadfromfile
	if (!this->texture.loadFromFile("Texture/helicopter-spritesheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::initSprite()
{
	//set texture to sprite
	this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);

	//resize sprite
	this->sprite.scale(0.9f, 0.9f);
}

void Player::initAnimation()
{
	this->animationTime.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimation();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getpos() const
{
	return this->sprite.getPosition();
}

sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::healHp(const int value)
{
	this->hp += value;
	if (this->hp > this->hpMax)
	{
		this->hp = hpMax;
	}
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

const bool Player::shotgunAttack()
{

	if (this->shotgunCooldown >= this->shotgunCooldownMax)
	{
		this->shotgunCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.3f;
	}
}

void Player::updateShotgun()
{
	if (this->shotgunCooldown < this->shotgunCooldownMax)
	{
		this->shotgunCooldown += 0.3f;
	}
}

void Player::updateAnimation()
{
	if (this->animationTime.getElapsedTime().asSeconds() >= 0.125f)
	{
		if (this->flyNum >= 4)
		{
			this->flyNum = 1;
		}
		if (this->flying == true)
		{
			switch (this->flyNum)
			{
			case 1: this->preHeight = 0.f;
				break;
			case 2: this->preHeight = 80.f;
				break;
			case 3:	this->preHeight = 160.f;
				break;
			case 4:	this->preHeight = 320.f;
				break;
			}
			this->currentFrame = sf::IntRect(this->preWidth, this->preHeight, this->width, this->height);
			this->sprite.setTextureRect(this->currentFrame);
			this->flyNum++;
		}
		this->animationTime.restart();
	}
}

void Player::update()
{
	this->updateAttack();
	this->updateShotgun();
	this->updateAnimation();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
