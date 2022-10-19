#include "GameState.h"

GameState::GameState(sf::RenderTarget* window)
	:State(window)
{

}

GameState::~GameState()
{

}

void GameState::endState()
{
	std::cout << "end\n";
}

void GameState::updateKeyBinds(const float& dt)
{
	this->checkforquit();
}

void GameState::update(const float& dt)
{
	this->updateKeyBinds(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A\n";
}

void GameState::render(sf::RenderTarget* target)
{

}
