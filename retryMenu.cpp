#include "retryMenu.h"

retryMenu::retryMenu(float width, float height)
{
	font.loadFromFile("Fonts/Dosis-Light.ttf");

	youDiedText.setFont(font);
	youDiedText.setCharacterSize(72);
	youDiedText.setFillColor(sf::Color::Red);
	youDiedText.setString("YOU DIED!");
	youDiedText.setPosition(width / 2.f - 100,height / 3.f - 150);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setCharacterSize(70);
	menu[0].setString("RESTART");
	menu[0].setPosition(sf::Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 + 50));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setCharacterSize(70);
	menu[1].setString("EXIT");
	menu[1].setPosition(sf::Vector2f(width / 2 - 50, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 + 50));

	selectedItemIndex = 0;
}

retryMenu::~retryMenu()
{

}
void retryMenu::draw(sf::RenderWindow& window)
{
	window.draw(youDiedText);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void retryMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}
void retryMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);

	}
}