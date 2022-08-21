#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Game.h"

enum level {
	START,
	BEGINNER,
	INTERMEDIATE,
	EXPERT,
	CLOSE
};

int main()
{
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
	bool lost{ false }, win{ false };
	while (!lost && !win)
	{
		const float menuWidth{ 400.0 }, menuHeight{ 400.0 };
		level level{ START };

		sf::RenderWindow window(sf::VideoMode(menuWidth, menuHeight), "Minesweepers");

		Menu menu(menuWidth, menuHeight);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i pos = sf::Mouse::getPosition(window);
						int index = menu.select(pos);
						switch (index)
						{
						case 0:
							level = BEGINNER;
							window.close();
							break;
						case 1:
							level = INTERMEDIATE;
							window.close();
							break;
						case 2:
							level = EXPERT;
							window.close();
							break;
						case 3:
							level = CLOSE;
							window.close();
							break;
						case -1:
							break;
						}
					}
				}
			}
			window.clear();
			menu.draw(window);
			window.display();
		}

		int gameWidth{}, gameHeight{}, gameMines{};
		switch (level)
		{
		case BEGINNER:
			gameWidth = 9;
			gameHeight = 9;
			gameMines = 10;
			break;
		case INTERMEDIATE:
			gameWidth = 16;
			gameHeight = 16;
			gameMines = 40;
			break;
		case EXPERT:
			gameWidth = 30;
			gameHeight = 16;
			gameMines = 99;
			break;
		case CLOSE:
			return 0;
		}

		Game game(gameWidth, gameHeight, gameMines);
		sf::RenderWindow windowGame(sf::VideoMode(Cell::CELL_SIZE * game.getWidth(), Cell::CELL_SIZE * game.getHeight()), "Minesweepers");

		while (windowGame.isOpen())
		{
			sf::Event event;
			while (!lost && !win)
			{
				while (windowGame.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						windowGame.close();
					if (event.type == sf::Event::MouseButtonReleased) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							sf::Vector2i pos = sf::Mouse::getPosition(windowGame);
							game.changeStatus(pos, OPEN);
						}
						else if ((event.mouseButton.button == sf::Mouse::Right)) {
							sf::Vector2i pos = sf::Mouse::getPosition(windowGame);
							game.changeStatus(pos, FLAG);
						}
					}
				}

				windowGame.clear();
				game.drawBoard(windowGame);
				windowGame.display();
				lost = game.isLost();
				win = game.isWin();
			}

			lost = false;
			win = false;
			break;
		}
	}
	

	return 0;
}