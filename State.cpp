#include "State.h"

State::State(sf::RenderTarget* window)
{
	this->window = window;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkforquit()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}
