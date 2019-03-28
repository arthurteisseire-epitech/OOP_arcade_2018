/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include <random>
#include "Map.hpp"
#include "Converter.hpp"

arc::Map::Map(const Position &dimension) :
	_dimension(dimension),
	_cells(),
	_qix(initQix())
{
	_cells.reserve(static_cast<size_t>(_dimension.x));
	_sprites.reserve(static_cast<size_t>(_dimension.x) * _dimension.y);
	for (unsigned int y = 0; y < _dimension.x; ++y) {
		_cells.emplace_back(std::vector<Cell>());
		_cells[y].reserve(static_cast<size_t>(_dimension.y));
		for (unsigned int x = 0; x < _dimension.y; ++x)
			fillCells(Position(x, y));
	}
}

arc::Qix arc::Map::initQix()
{
	std::random_device randomDevice;
	Position qixPos(abs(randomDevice() % _dimension.x - 2) + 1, abs(randomDevice() % _dimension.y - 2) + 1);

	return Qix(qixPos);
}

void arc::Map::fillCells(const Position &pos)
{
	if (pos.x == 0 || pos.x == _dimension.x - 1 || pos.y == 0 || pos.y == _dimension.y - 1)
		_cells[pos.y].emplace_back(Cell(Cell::BORDER));
	else if (pos == _qix.position())
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
	Position startOfNonQixZone(0, 0);

	for (unsigned int y = 0; y < _cells.size(); ++y)
		for (unsigned int x = 0; x < _cells[y].size(); ++x)
			if (_cells[y][x].state() == Cell::TRAIL) {
				_cells[y][x].alterState(Cell::BORDER);
				if (startOfNonQixZone == Position(0, 0) && x != 0 && x != _dimension.x && y != 0 && y != _dimension.y)
					startOfNonQixZone = findNonQixZone(Position{x, y});
			}
	if (startOfNonQixZone != Position(0, 0))
		fillZone(startOfNonQixZone);
}

arc::Position arc::Map::findNonQixZone(const Position &pos)
{
	Position posToLook(0, 0);
	Position oppositePos(0, 0);

	findPosToLook(&posToLook, &oppositePos, pos);
	if (isQixInZone(posToLook))
		return oppositePos;
	return posToLook;
}

void arc::Map::findPosToLook(Position *posToLook, Position *oppositePos, const Position &currPos) const
{
	if (tryPosition(currPos + Position(1, 0), posToLook, oppositePos, currPos - Position(1, 0)))
		return;
	if (tryPosition(currPos - Position(1, 0), posToLook, oppositePos, currPos + Position(1, 0)))
		return;
	if (tryPosition(currPos + Position(0, 1), posToLook, oppositePos, currPos - Position(0, 1)))
		return;
	if (tryPosition(currPos - Position(0, 1), posToLook, oppositePos, currPos + Position(0, 1)))
		return;
	*oppositePos = currPos;
	*posToLook = currPos;
}

bool arc::Map::tryAllZonePositions(const arc::Position &position)
{
	if (position == _qix.position())
		return true;
	_cells[position.y][position.x].alterState(Cell::TMP);
	if (_cells[position.y + 1][position.x].state() == Cell::WALKABLE || _cells[position.y + 1][position.x].state() == Cell::QIX)
		if (tryAllZonePositions({position.x, position.y + 1}))
			return true;
	if (_cells[position.y - 1][position.x].state() == Cell::WALKABLE || _cells[position.y - 1][position.x].state() == Cell::QIX)
		if (tryAllZonePositions({position.x, position.y - 1}))
			return true;
	if (_cells[position.y][position.x + 1].state() == Cell::WALKABLE || _cells[position.y][position.x + 1].state() == Cell::QIX)
		if (tryAllZonePositions({position.x + 1, position.y}))
			return true;
	if (_cells[position.y][position.x - 1].state() == Cell::WALKABLE || _cells[position.y][position.x - 1].state() == Cell::QIX)
		if (tryAllZonePositions({position.x - 1, position.y}))
			return true;
	return false;
}

bool arc::Map::isQixInZone(const arc::Position &position)
{
	bool res = tryAllZonePositions(position);

	for (auto &_cell : _cells)
		for (auto &x : _cell)
			if (x.state() == Cell::TMP)
				x.alterState(Cell::WALKABLE);
	return res;
}

bool arc::Map::tryPosition(const Position posToTry, Position *posToLook, Position *oppositePos,
			   const Position oppositePosToTry) const
{
	if (!(posToTry.x > 0 && posToTry.x < _dimension.x && posToTry.y > 0 && posToTry.y < _dimension.y))
		return false;
	if (_cells[posToTry.y][posToTry.x].state() == arc::Cell::WALKABLE) {
		*posToLook = posToTry;
		*oppositePos = oppositePosToTry;
		return true;
	}
	return false;
}

void arc::Map::fillZone(const arc::Position &position)
{
	_cells[position.y][position.x].alterState(Cell::BORDER);
	if (_cells[position.y + 1][position.x].state() == Cell::WALKABLE)
		 fillZone({position.x, position.y + 1});
	if (_cells[position.y - 1][position.x].state() == Cell::WALKABLE)
		fillZone({position.x, position.y - 1});
	if (_cells[position.y][position.x + 1].state() == Cell::WALKABLE)
		fillZone({position.x + 1, position.y});
	if (_cells[position.y][position.x - 1].state() == Cell::WALKABLE)
		fillZone({position.x - 1, position.y});
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