#pragma once
#include<SFML/Graphics.hpp>
class Background
{
public:
    Background(sf::Texture* text, float speed);

    void Update(float deltaTime);
    void render(sf::RenderWindow* target);
private:
    sf::RectangleShape body[2];
    sf::Vector2f position;
    sf::Vector2f size;

    float speed;
};
