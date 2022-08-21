#pragma once
#include <vector>
#include <memory>
#include <unordered_set>
#include <cstdlib>
#include <time.h>
#include "Cell.h"

class Game
{
	const int width;
	const int height;
	const int mines;
	bool lost;
	bool win;
	bool firstClick;
	int remainingCells;
	std::vector<std::vector<std::shared_ptr<Cell>>> board;
	std::unordered_set<int> minesLocation;
public:
	Game(int _width = 30, int _height = 16, int _mines = 99);
	void drawBoard(sf::RenderWindow& window) ;
	void generateMines(int x, int y);
	void assignMines();
	void calculateCells();
	void changeStatus(const sf::Vector2i& pos, CellStatus status);
	bool isValidCell(int row, int col);
	void openAdjacentCells(int x, int y);
	void startGame(const sf::Vector2i& pos);
	const int getWidth() const;
	const int getHeight() const;
	const bool isLost() const;
	const bool isWin() const;

};

