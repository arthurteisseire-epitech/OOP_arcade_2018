/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include "Map.hpp"
#include "Converter.hpp"

arc::Map::Map(int width, int height) : _width(width),
                                       _height(height),
                                       _cells()
{
	_cells.reserve(static_cast<size_t>(height));
	_sprites.reserve(static_cast<size_t>(height) * width);
	for (int y = 0; y < height; ++y) {
		_cells.emplace_back(std::vector<Cell>());
		_cells[y].reserve(static_cast<size_t>(width));
		for (int x = 0; x < width; ++x) {
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
				_cells[y].emplace_back(Cell(Cell::BORDER));
			else
				_cells[y].emplace_back(Cell(Cell::WALKABLE));
			_cells[y][x].setSize(Converter::SizeToPourcent(_width, _height));
			_cells[y][x].setPosition(Converter::PosToPourcent({x, y}, _width, _height));
			_sprites.emplace_back(_cells[y][x].sprite());
		}
	}
}

arc::Map::~Map()
{
	_cells.clear();
}

void arc::Map::transformTrailToBorder()
{
	for (auto &row : _cells)
		for (auto &x : row)
			if (x.state() == Cell::TRAIL)
				x.alterState(Cell::BORDER);
}

void arc::Map::trail(const arc::Position &pos)
{
	_cells[pos.y][pos.x].alterState(Cell::TRAIL);
}

bool arc::Map::inBorder(const arc::Position &pos) const
{
	return in(pos) && _cells[pos.y][pos.x].state() == Cell::BORDER;
}

bool arc::Map::inWalkable(const arc::Position &pos) const
{
	return in(pos) && _cells[pos.y][pos.x].state() == Cell::WALKABLE;
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

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Map::getSprites() const
{
	return _sprites;
}
