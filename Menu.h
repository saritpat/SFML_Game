#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
#include<SFML/Audio.hpp>
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { selectSound.play(); return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	
	sf::Text name;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::SoundBuffer move, select;
	sf::Sound moveSound, selectSound;

};



