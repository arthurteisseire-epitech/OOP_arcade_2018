/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include "Map.hpp"
#include "Converter.hpp"
#include <random>

#include <iostream>
arc::Map::Map(const Position &dimension) :
	_dimension(dimension),
	_cells(),
	_qix(Cell::QIX)
{
	std::random_device randomDevice;
	Position qixPos(abs(randomDevice() % _dimension.x - 2) + 1, abs(randomDevice() % _dimension.y - 2) + 1);

	_cells.reserve(static_cast<size_t>(_dimension.x));
	_sprites.reserve(static_cast<size_t>(_dimension.x) * _dimension.y);
	for (unsigned int y = 0; y < _dimension.x; ++y) {
		_cells.emplace_back(std::vector<Cell>());
		_cells[y].reserve(static_cast<size_t>(_dimension.y));
		for (unsigned int x = 0; x < _dimension.y; ++x)
			fillCells(Position(x, y), qixPos);
	}
}

void arc::Map::fillCells(const Position &pos, const Position &qixPosition)
{
	if (pos.x == 0 || pos.x == _dimension.x - 1 || pos.y == 0 || pos.y == _dimension.y - 1)
		_cells[pos.y].emplace_back(Cell(Cell::BORDER));
	else if (pos == qixPosition)
		_cells[pos.y].emplace_back(Cell(Cell::QIX));
	else
		_cells[pos.y].emplace_back(Cell(Cell::WALKABLE));
	_cells[pos.y][pos.x].setSize(Converter::SizeToPercent(_dimension));
	_cells[pos.y][pos.x].setPosition(Converter::PosToPercent({pos.x, pos.y}, _dimension));
	_sprites.emplace_back(_cells[pos.y][pos.x].sprite());
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
	return pos.x < _dimension.x && pos.y < _dimension.y;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Map::getSprites() const
{
	return _sprites;
}

arc::Position arc::Map::dimension() const
{
	return _dimension;
}
