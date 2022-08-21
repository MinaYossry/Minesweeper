#include "Cell.h"

const float Cell::CELL_SIZE = 32.0;


Cell::Cell(float _x, float _y, bool _mine)
	: position{ sf::Vector2f(_x,_y) }, count{}, mine{ _mine }, status{ CLOSED } {
	color.loadFromFile("images/tiles.jpg");
	cell.setTexture(color);
	cell.setPosition(position);
}

const sf::Sprite& Cell::getCell() const {
	return cell;
}

void Cell::setMine(bool _mine)
{
	mine = _mine;
}

bool Cell::isMine()
{
	return mine;
}

const CellStatus Cell::getStatus() const
{
	return status;
}

const int Cell::getCount() const
{
	return count;
}

void Cell::setStatus(CellStatus _status)
{
	status = _status;
}

void Cell::setCount(int _count)
{
	count = _count;
}

void Cell::drawCell(sf::RenderWindow& window)
{
	if (status == OPEN) {
		if (mine)
			cell.setTextureRect(sf::IntRect(CELL_SIZE * 9, 1, CELL_SIZE, CELL_SIZE));
		else
			cell.setTextureRect(sf::IntRect(CELL_SIZE * count, 1, CELL_SIZE, CELL_SIZE));
	}
	else if (status == FLAG) {
		cell.setTextureRect(sf::IntRect(CELL_SIZE * 11, 1, CELL_SIZE, CELL_SIZE));
	}
	else {
		cell.setTextureRect(sf::IntRect(CELL_SIZE * 10, 1, CELL_SIZE, CELL_SIZE));
	}
	window.draw(cell);
}
