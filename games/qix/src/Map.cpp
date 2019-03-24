/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include "Map.hpp"

arc::Map::Map(int width, int height) : _width(width),
                                       _height(height),
                                       _cells()
{
	_cells.reserve(static_cast<size_t>(height));
	for (int y = 0; y < height; ++y) {
		_cells.emplace_back(std::vector<Cell>());
		_cells[y].reserve(static_cast<size_t>(width));
		for (int x = 0; x < width; ++x)
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
				_cells[y].emplace_back(Cell(Cell::BORDER));
			else
				_cells[y].emplace_back(Cell(Cell::WALKABLE));
	}
}

arc::Map::~Map()
{
	_cells.clear();
}

bool arc::Map::inBorder(const arc::Position &pos) const
{
	return in(pos) && _cells[pos.x][pos.y].state() == Cell::BORDER;
}

bool arc::Map::inWalkable(const arc::Position &pos) const
{
	return in(pos) && _cells[pos.x][pos.y].state() == Cell::WALKABLE;
}

bool arc::Map::in(const arc::Position &pos) const
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < _width && pos.y < _height;
}

int arc::Map::width() const
{
	return _width;
}

int arc::Map::height() const
{
	return _height;

}
