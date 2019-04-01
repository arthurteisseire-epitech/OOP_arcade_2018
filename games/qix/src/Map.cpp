/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include <random>
#include <algorithm>
#include "Map.hpp"
#include "Converter.hpp"

arc::Map::Map(const Position &dimension) :
	_dimension(dimension),
	_cells(),
	_qix(initQix()),
	_qixPositions(findQixPositions()),
	_isPlayerAlive(true)
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
	const unsigned int radius = 2;
	Position qixPos(abs(randomDevice() % _dimension.x - (radius + 1) * 2) + radius + 1, abs(randomDevice() % _dimension.y - (radius + 1) * 2) + radius + 1);

	return Qix(qixPos);
}

const std::vector<arc::Position> arc::Map::findQixPositions() const
{
	const Position &qixCenter = _qix.position();
	std::vector<Position> qixPos;

	for (unsigned int y = 0; y < _dimension.y; ++y)
		for (unsigned int x = 0; x < _dimension.x; ++x) {
			Position currPos(x, y);
			if (qixCenter.distance(currPos) <= _qix.radius())
				qixPos.push_back(currPos);
		}
	return qixPos;
}

void arc::Map::fillCells(const Position &pos)
{
	if (pos.x == 0 || pos.x == _dimension.x - 1 || pos.y == 0 || pos.y == _dimension.y - 1)
		_cells[pos.y].emplace_back(Cell(Cell::BORDER));
	else if (std::find(_qixPositions.begin(), _qixPositions.end(), pos) != _qixPositions.end())
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
				startOfNonQixZone = findNonQixZone(Position{x, y});
				if (isInNoBorders(startOfNonQixZone))
					fillZone(startOfNonQixZone);
			}
}

arc::Position arc::Map::findNonQixZone(const Position &pos)
{
	Position posToLook(0, 0);
	Position oppositePos(0, 0);

	findPosToLook(&posToLook, &oppositePos, pos);
	if (_cells[posToLook.y][posToLook.x].state() != Cell::WALKABLE)
		return posToLook;
	if (isQixInZone(posToLook)) {
		if (!isInNoBorders(oppositePos))
			return {0, 0};
		return oppositePos;
	}
	if (!isInNoBorders(posToLook))
		return {0, 0};
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

bool arc::Map::isQixInZone(const arc::Position &position)
{
	bool res = tryAllZonePositions(position);

	for (auto &_cell : _cells)
		for (auto &x : _cell)
			if (x.state() == Cell::TMP)
				x.alterState(Cell::WALKABLE);
	return res;
}

bool arc::Map::tryAllZonePositions(const arc::Position &position)
{
	if (_cells[position.y][position.x].state() == Cell::QIX)
		return true;
	_cells[position.y][position.x].alterState(Cell::TMP);
	if (_cells[position.y + 1][position.x].state() == Cell::WALKABLE ||
	    _cells[position.y + 1][position.x].state() == Cell::QIX)
		if (tryAllZonePositions({position.x, position.y + 1}))
			return true;
	if (_cells[position.y - 1][position.x].state() == Cell::WALKABLE ||
	    _cells[position.y - 1][position.x].state() == Cell::QIX)
		if (tryAllZonePositions({position.x, position.y - 1}))
			return true;
	if (_cells[position.y][position.x + 1].state() == Cell::WALKABLE ||
	    _cells[position.y][position.x + 1].state() == Cell::QIX)
		if (tryAllZonePositions({position.x + 1, position.y}))
			return true;
	if (_cells[position.y][position.x - 1].state() == Cell::WALKABLE ||
	    _cells[position.y][position.x - 1].state() == Cell::QIX)
		if (tryAllZonePositions({position.x - 1, position.y}))
			return true;
	return false;
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
	if (_cells[position.y][position.x].state() == Cell::WALKABLE)
		_cells[position.y][position.x].alterState(Cell::NON_WALKABLE);
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

bool arc::Map::isInBorders(const arc::Position &pos) const
{
	return isIn(pos) && _cells[pos.y][pos.x].state() == Cell::BORDER;
}

bool arc::Map::isInNoBorders(const arc::Position &pos) const
{
	return isIn(pos) && _cells[pos.y][pos.x].state() != Cell::BORDER && _cells[pos.y][pos.x].state() != Cell::TRAIL;
}

bool arc::Map::isInWalkable(const arc::Position &pos) const
{
	return isIn(pos) && _cells[pos.y][pos.x].state() == Cell::WALKABLE;
}

bool arc::Map::isIn(const arc::Position &pos) const
{
	return pos.x < _dimension.x && pos.y < _dimension.y;
}

bool arc::Map::isNextToWalkable(const Position &pos) const
{
	if (isIn({pos.y + 1, pos.x}) && _cells[pos.y + 1][pos.x].state() == Cell::WALKABLE)
		return true;
	if (isIn({pos.y - 1, pos.x}) && _cells[pos.y - 1][pos.x].state() == Cell::WALKABLE)
		return true;
	if (isIn({pos.y, pos.x + 1}) && _cells[pos.y][pos.x + 1].state() == Cell::WALKABLE)
		return true;
	if (isIn({pos.y, pos.x - 1}) && _cells[pos.y][pos.x - 1].state() == Cell::WALKABLE)
		return true;

	if (isIn({pos.y + 1, pos.x + 1}) && _cells[pos.y + 1][pos.x + 1].state() == Cell::WALKABLE)
		return true;
	if (isIn({pos.y - 1, pos.x - 1}) && _cells[pos.y - 1][pos.x - 1].state() == Cell::WALKABLE)
		return true;
	if (isIn({pos.y - 1, pos.x + 1}) && _cells[pos.y - 1][pos.x + 1].state() == Cell::WALKABLE)
		return true;
	return isIn({pos.y + 1, pos.x - 1}) && _cells[pos.y + 1][pos.x - 1].state() == Cell::WALKABLE;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Map::getSprites() const
{
	return _sprites;
}

arc::Position arc::Map::dimension() const
{
	return _dimension;
}

int arc::Map::findPercentCovered() const
{
	unsigned int possessedArea = 0;

	for (auto &raw : _cells)
		for (auto &x : raw)
			if (x.state() == Cell::NON_WALKABLE)
				++possessedArea;
	return possessedArea * 100 / (_dimension.x * _dimension.y);
}

void arc::Map::updateQix(float dTime)
{
	static float localDTime = 0;
	std::random_device randomDevice;
	unsigned int randomRes = randomDevice();

	if (localDTime >= 0.05) {
		moveQix(Position(randomRes % 2, (randomRes + 1) % 2), static_cast<bool>(randomDevice() % 2));
		localDTime = 0;
	} else
		localDTime += dTime;
}

void arc::Map::moveQix(const Position &direction, bool sign)
{
	if (checkMovement(direction, sign))
		return;
	_qix.move(direction);
	for (auto &pos : _qixPositions) {
		_cells[pos.y][pos.x].alterState(Cell::WALKABLE);
		sign ? (pos += direction) : (pos -= direction);
	}
	for (auto &pos : _qixPositions)
		_cells[pos.y][pos.x].alterState(Cell::QIX);
}

bool arc::Map::checkMovement(const arc::Position &direction, bool sign)
{
	for (const auto &pos : _qixPositions) {
		arc::Position posToTest = (sign ? pos + direction : pos - direction);
		switch (_cells[posToTest.y][posToTest.x].state()) {
		case Cell::BORDER:
			updateQix(1);
			return true;
		case Cell::TRAIL:
			_isPlayerAlive = false;
			return true;
		default:
			continue;
		}
	}
	return false;
}

bool arc::Map::qixTouchedTrail() const
{
	return !_isPlayerAlive;
}
