#include "Menu.h"

Menu::Menu(float width, float height)
	: selectedItemIndex{-1}, menu(MAX_ITEMS) {
	if (!font.loadFromFile("arial.ttf"))
	{

	}

	for (auto& text : menu)
	{
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	}

	menu.at(0).setString("Beginner");
	menu.at(0).setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));
	menu.at(1).setString("Intermediate");
	menu.at(1).setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));
	menu.at(2).setString("Expert");
	menu.at(2).setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));
	menu.at(3).setString("Quit");
	menu.at(3).setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 4));
}

void Menu::draw(sf::RenderWindow& window) {
	for (int i{}; i < MAX_ITEMS; i++)
	{
		window.draw(menu.at(i));
	}
}

int Menu::select(sf::Vector2i pos)
{
	int x = pos.x;
	int y = pos.y;
	for (int i{}; i < MAX_ITEMS; i++)
	{
		if (menu.at(i).getGlobalBounds().contains(sf::Vector2f(x,y))) {
			return i;
		}
	}
	return -1;
}
