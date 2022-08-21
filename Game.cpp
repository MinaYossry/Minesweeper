#include "Game.h"
#include <iostream>

Game::Game(int _width, int _height, int _mines)
	: width{ _width }, height{ _height }, mines{ _mines }, firstClick{ true }, lost{ false }, win{ false }, remainingCells{_width * _height - _mines}{
	for (int i{}; i < height; i++) {
		std::vector<std::shared_ptr<Cell>> row;
		for (int j{}; j < width; j++) {
			bool mine = false;
			row.emplace_back(std::make_shared<Cell>(j * Cell::CELL_SIZE, i * Cell::CELL_SIZE, mine));
		}
		board.emplace_back(std::move(row));
	}

	
}

void Game::drawBoard(sf::RenderWindow& window) {
	for (const auto& row : board) {
		for (const auto& cell : row)
			cell->drawCell(window);
	}
}

void Game::generateMines(int x, int y)
{
	std::unordered_set<int> offLimits;
	for (int i{ -1 }; i < 2; i++) {
		for (int j{ -1 }; j < 2; j++) {
			if (isValidCell(x + i, y + j)) {
				offLimits.insert((x + i) * width + (y + j));
			}
		}
	}

	srand(time(0));
	int total{ width * height };
	while (minesLocation.size() < mines) {
		int location = rand() % total;
		if (offLimits.count(location) == 0)
			minesLocation.insert(location);
	}
}

void Game::assignMines()
{
	for (const auto& location : minesLocation) {
		int y = location % width;
		int x = location / width;
		board.at(x).at(y)->setMine();
	}
}

void Game::calculateCells()
{
	for (int row{}; row < height; row++) {
		for (int col{}; col < width; col++) {
			int count{};
			for (int i{-1}; i < 2; i++) {
				for (int j{ -1 }; j < 2; j++) {
					if (i == 0 && j == 0)
						continue;

					if (isValidCell(row + i, col + j)) {
						if (board.at(row + i).at(col + j)->isMine())
							count++;
					}
				}
			}
			board.at(row).at(col)->setCount(count);
		}
	}
}

void Game::changeStatus(const sf::Vector2i& pos, CellStatus status)
{
	if (!lost && !win)
	{
		if (firstClick && status == OPEN) {
			startGame(pos);
		}
		else {
			int x = pos.y / Cell::CELL_SIZE;
			int y = pos.x / Cell::CELL_SIZE;
			if (board.at(x).at(y)->getStatus() == FLAG) {
				if (status == FLAG) {
					board.at(x).at(y)->setStatus(CLOSED);
				}
			}
			else if (board.at(x).at(y)->getStatus() == CLOSED) {
				if (status == OPEN) {
					if (board.at(x).at(y)->isMine()) {
						for (auto& row : board) {
							for (auto& cell : row) {
								cell->setStatus(OPEN);
							}
						}
						lost = true;
					}
					else {
						openAdjacentCells(x, y);
						if (remainingCells == 0)
							win = true;
					}
				}
				else {
					board.at(x).at(y)->setStatus(status);
				}
			}
		}
		
	}
}

bool Game::isValidCell(int row, int col)
{
	return row >= 0 && row < height && col >= 0 && col < width;
}

void Game::openAdjacentCells(int x, int y)
{
	if (!isValidCell(x, y))
		return;

	if (board.at(x).at(y)->isMine())
		return;

	else if (board.at(x).at(y)->getStatus() == OPEN)
		return;

	board.at(x).at(y)->setStatus(OPEN);
	remainingCells--;

	if (board.at(x).at(y)->getCount() == 0) {
		for (int i{ -1 }; i < 2; i++) {
			for (int j{ -1 }; j < 2; j++) {
				if (i == 0 && j == 0)
					continue;

				openAdjacentCells(x + i, y + j);
			}
		}
	}
}

void Game::startGame(const sf::Vector2i& pos)
{
	int x = pos.y / Cell::CELL_SIZE;
	int y = pos.x / Cell::CELL_SIZE;

	generateMines(x, y);
	assignMines();
	calculateCells();

	openAdjacentCells(x, y);
	firstClick = false;
}

const int Game::getWidth() const
{
	return width;
}

const int Game::getHeight() const
{
	return height;
}

const bool Game::isLost() const
{
	return lost;
}

const bool Game::isWin() const
{
	return win;
}
