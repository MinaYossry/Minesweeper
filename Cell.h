#pragma once
#include <SFML/Graphics.hpp>

enum CellStatus {
	CLOSED,
	OPEN,
	FLAG
};

class Cell
{
	
	sf::Sprite cell;
	sf::Texture color;
	sf::Vector2f position;
	bool mine;
	CellStatus status;
	int count;

public:
	Cell(float _x, float _y, bool _mine = false);
	const sf::Sprite& getCell() const;
	const static float CELL_SIZE;
	void setMine(bool _mine = true);
	bool isMine();
	const CellStatus getStatus() const;
	const int getCount() const;
	void setStatus(CellStatus _status);
	void setCount(int _count);
	void drawCell(sf::RenderWindow& window);
};

