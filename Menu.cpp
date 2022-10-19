#include "Menu.h"

Menu::Menu(float width, float height)
{
	font.loadFromFile("Fonts/Dosis-Light.ttf");

	name.setFont(font);
	name.setFillColor(sf::Color::White);
	name.setCharacterSize(40);
	name.setOutlineColor(sf::Color::Black);
	name.setOutlineThickness(1.f);
	name.setString("By\n	63010956 Saritpat Niyomthong");
	name.setPosition(sf::Vector2f(10, 10));

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setCharacterSize(70);
	menu[0].setString("PLAY");
	menu[0].setPosition(sf::Vector2f(width / 2 - 50 + 400, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setCharacterSize(70);
	menu[1].setString("SCORE");
	menu[1].setPosition(sf::Vector2f(width / 2 - 50 + 400, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setCharacterSize(70);
	menu[2].setString("EXIT");
	menu[2].setPosition(sf::Vector2f(width / 2 - 50 + 400, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(name);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
