#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>

class State
{
private:
	sf::RenderTarget* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderTarget* window);
	virtual ~State();
	const bool& getQuit() const;

	virtual void checkforquit();

	virtual void endState() = 0;
	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

