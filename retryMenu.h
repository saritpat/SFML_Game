#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#define MAX_NUMBER_OF_ITEMS 2
class retryMenu
{
public:

	retryMenu(float width, float height);
	~retryMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { selectSound.play(); return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text youDiedText;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

	sf::SoundBuffer move, select;
	sf::Sound moveSound, selectSound;
};

