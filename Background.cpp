#include "Background.h"

Background::Background(sf::Texture* texture, float speed)
{
    this->speed = speed;
    this->size = sf::Vector2f(1280.f, 720.f);

    body[0].setSize(size);
    body[1].setSize(size);
    body[0].setTexture(texture);
    body[1].setTexture(texture);
    body[0].setScale(3, 3);
    body[1].setScale(3, 3);

    if (speed < 0)//left
        body[1].setPosition(size.x - 2.0f, 0.0f);
    else body[1].setPosition(size.x + 2.0f, 0.0f);

}

void Background::Update(float deltaTime)
{
    for (int i = 0; i < 2; i++)
    {
        position = body[i].getPosition();

        body[i].move(speed * deltaTime, 0);

        if (position.x <= -size.x && speed < 0)
            body[i].setPosition(size.x - 4.0f, position.y);
        else if (position.x >= size.x && speed > 0)
            body[i].setPosition(-size.x + 4.0f, position.y);
    }
}

void Background::render(sf::RenderWindow* target)
{
    target->draw(this->body[0]);
    target->draw(this->body[1]);
}
