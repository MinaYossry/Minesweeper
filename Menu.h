#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu
{
public:
	Menu(float width, float height);
	void draw(sf::RenderWindow& window);
	int getPressedItem() { return selectedItemIndex; }
	int select(sf::Vector2i pos);
private:
	int selectedItemIndex;
	sf::Font font;
	std::vector<sf::Text> menu;
	const static int MAX_ITEMS = 4;
};

