/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Snake.cpp
*/

#include "Sprite.hpp"
#include "Snake.hpp"
#include "MathUtils.hpp"

#include <iostream>

const std::unordered_map<arc::Snake::Direction, pos_t> arc::Snake::_directionMap = {{UP, {0, -1}}, {DOWN, {0, 1}},
	{RIGHT, {1, 0}}, {LEFT, {-1, 0}}};

const std::map<pos_t, arc::Snake::Direction> arc::Snake::_directionPosMap = {{{0, -1}, UP}, {{0, 1}, DOWN},
	{{1, 0}, RIGHT}, {{-1, 0}, LEFT}};

const std::unordered_map<arc::Snake::Direction, std::vector<std::string>> arc::Snake::_assetsMap = {
	{UP, {"snake_head_up.png", "snake_middle_vertical.png", "snake_tail_up.png"}},
	{DOWN, {"snake_head_down.png", "snake_middle_vertical.png", "snake_tail_down.png"}},
	{RIGHT, {"snake_head_right.png", "snake_middle_horizontal.png", "snake_tail_right.png"}},
	{LEFT, {"snake_head_left.png", "snake_middle_horizontal.png", "snake_tail_left.png"}}};

const std::map<std::pair<arc::Snake::Direction, arc::Snake::Direction>, std::string> arc::Snake::_curvedAssets = {
	{{DOWN, LEFT}, "snake_middle_down_left.png"}, {{DOWN, RIGHT}, "snake_middle_down_right.png"},
	{{UP, RIGHT}, "snake_middle_up_right.png"}, {{UP, LEFT}, "snake_middle_up_left.png"},
	{{LEFT, UP}, "snake_middle_down_right.png"}, {{LEFT, DOWN}, "snake_middle_up_right.png"},
	{{RIGHT, UP}, "snake_middle_down_left.png"}, {{RIGHT, DOWN}, "snake_middle_up_left.png"}};

arc::Snake::Snake(const pos_t &startPos, unsigned int size, const pos_t &mapSize) :
	_mapSize(mapSize),
	_isDead(false)
{
	pos_t posRes;
	std::unique_ptr<Sprite> actualSprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _assetsMap.at(LEFT)[0]);

	appendSprite(startPos, actualSprite, mapSize);
	_bodyPositions.emplace_back(startPos);
	for (unsigned int i = 1; i < size - 1; ++i) {
		posRes = startPos + pos_t{i, 0};
		_bodyPositions.emplace_back(posRes);
		actualSprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _assetsMap.at(LEFT)[1]);
		appendSprite(posRes, actualSprite, mapSize);
	}
	_bodyPositions.emplace_back(startPos + pos_t{size - 1, 0});
	actualSprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _assetsMap.at(LEFT)[2]);
	appendSprite(posRes + pos_t{1, 0}, actualSprite, mapSize);
}

void arc::Snake::appendSprite(const pos_t &posRes, std::unique_ptr<arc::Sprite> &actualSprite, const pos_t &size)
{
	actualSprite->setPosition(posRes / size);
	actualSprite->setSize(pos_t{1.0, 1.0} / size);
	_cacheAssets.emplace_back(std::move(actualSprite));
}

void arc::Snake::eat()
{
	const auto tail = dynamic_cast<Sprite *>(_cacheAssets[_bodyPositions.size() - 1].get());
	const auto neckTail = dynamic_cast<Sprite *>(_cacheAssets[_bodyPositions.size() - 2].get());
	pos_t tailPosDir = findTailPosDirection();
	std::pair<float, float> newTailPos = tail->getPosition();
	std::unique_ptr<IComponent> newTailNeck = std::make_unique<Sprite>(neckTail->getTextureName(), tail->getSize(),
		tail->getPosition());

	newTailPos.first -= (float)tailPosDir.first / _mapSize.first;
	newTailPos.second -= (float)tailPosDir.second / _mapSize.second;
	_bodyPositions.push_back(_bodyPositions.back() - findTailPosDirection());
	tail->setPosition(newTailPos);
	_cacheAssets.insert(_cacheAssets.begin() + _bodyPositions.size() - 1, std::move(newTailNeck));
}

void arc::Snake::moveBody(const Direction &direction, bool changeDir)
{
	const pos_t &snakeDirection = _directionMap.at(direction);
	const pos_t resPos = _bodyPositions.front() + snakeDirection;
	const Direction lastDirection = findHeadDir();

	_bodyPositions.pop_back();
	if (isInSnake(resPos) || resPos.first < 0 || resPos.first >= _mapSize.first || resPos.second < 0 ||
		resPos.second >= _mapSize.second)
		_isDead = true;
	_bodyPositions.insert(_bodyPositions.begin(), resPos);
	updateSprites(direction, changeDir, lastDirection);
	printSnakePos();
}

void arc::Snake::updateSprites(const Direction &direction, bool changeDir, const Direction &lastDirection)
{
	const std::pair<float, float> headPos = dynamic_cast<Sprite *>(_cacheAssets[0].get())->getPosition();

	if (changeDir)
		turnHead(direction, headPos);
	updateAllBody(direction, headPos, changeDir, lastDirection);
}

std::pair<float, float> arc::Snake::findNewPos(const pos_t &snakeDirection,
					       const std::pair<float, float> &headPos) const
{
	return {headPos.first +
	(float)snakeDirection.first
	/ _mapSize.first,
		headPos.second +
		(float)snakeDirection.second
		/ _mapSize.second};
}

void arc::Snake::turnHead(const Direction &direction, const std::pair<float, float> &headPos)
{
	Sprite *sprite = new Sprite(PATH_TO_ASSETS + _assetsMap.at(direction)[0],
		pos_t{1.0, 1.0} / _mapSize, headPos);
	_cacheAssets.erase(_cacheAssets.begin());
	_cacheAssets.insert(_cacheAssets.begin(), std::unique_ptr<Sprite>(sprite));
}

const std::string &arc::Snake::findCurveSnake(const Direction &direction, const Direction &lastDirection) const
{
	return _curvedAssets.at({lastDirection, direction});
}

void arc::Snake::updateAllBody(const Direction &direction, const std::pair<float, float> &headPos, bool changeDir,
			       const Direction &lastDirection)
{
	pos_t snakeDirection = _directionMap.at(direction);
	const std::pair<float, float> newPos = findNewPos(snakeDirection, headPos);
	const std::pair<float, float> headPosSave = headPos;
	dynamic_cast<arc::Sprite *>(_cacheAssets[0].get())->setPosition(newPos);

	moveTailToNeck(direction, lastDirection, changeDir);
	createNewTail();
	dynamic_cast<arc::Sprite *>(_cacheAssets[1].get())->setPosition(headPosSave);
}

void arc::Snake::moveTailToNeck(const Direction &direction, const Direction &lastDirection, bool changeDir)
{
	std::unique_ptr<arc::IComponent> queueSprite = std::move(_cacheAssets[_bodyPositions.size() - 1]);

	_cacheAssets.erase(_cacheAssets.begin() + _bodyPositions.size() - 1);
	_cacheAssets.insert(_cacheAssets.begin() + 1, move(queueSprite));
	createNeckAsset(direction, lastDirection, changeDir);
}

void arc::Snake::createNewTail()
{
	const std::string asset = _assetsMap.at(_directionPosMap.at(findTailPosDirection()))[2];
	const Sprite *tail = dynamic_cast<Sprite *>(_cacheAssets[_bodyPositions.size() - 1].get());
	const std::pair<float, float> pos = tail->getPosition();
	const std::pair<float, float> size = tail->getSize();

	_cacheAssets[_bodyPositions.size() - 1] = std::make_unique<Sprite>(PATH_TO_ASSETS + asset, size, pos);
}

void arc::Snake::createNeckAsset(const Direction &direction, const Direction &lastDirection, bool changeDir)
{
	std::string spritePath;
	const Sprite *neckSprite = dynamic_cast<Sprite *>(_cacheAssets[1].get());
	const std::pair<float, float> pos = neckSprite->getPosition();
	const std::pair<float, float> size = neckSprite->getSize();

	if (changeDir)
		spritePath = findCurveSnake(direction, lastDirection);
	else
		spritePath = _assetsMap.at(direction)[1];
	spritePath = PATH_TO_ASSETS + spritePath;
	_cacheAssets[1] = std::make_unique<Sprite>(spritePath, size, pos);
}

bool arc::Snake::isInSnake(const pos_t &pos) const
{
	for (auto &snakePart : _bodyPositions)
		if (snakePart == pos)
			return true;
	return false;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Snake::getParts() const
{
	std::vector<std::reference_wrapper<const IComponent>> vec;

	for (const std::unique_ptr<IComponent> &asset : _cacheAssets)
		vec.emplace_back(*asset);
	return vec;
}

void arc::Snake::changeDirection(arc::PlayerDirection playerDir)
{
	Direction snakeDir = findHeadDir();

	moveBody(snakeDir * playerDir, playerDir != PLAYER_NONE);
}

arc::Snake::Direction arc::Snake::findHeadDir()
{
	pos_t pos_dir = _bodyPositions[0] - _bodyPositions[1];

	if (pos_dir.first != 0)
		return pos_dir.first == 1 ? RIGHT : LEFT;
	if (pos_dir.second != 0)
		return pos_dir.second == 1 ? DOWN : UP;
	throw "Snake has his head on part of his body";
}

pos_t arc::Snake::findTailPosDirection()
{
	unsigned long size = _bodyPositions.size();

	return _bodyPositions[size - 2] - _bodyPositions[size - 1];
}

void arc::Snake::printSnakePos()
{
	std::cout << "Sprites:" << std::endl;
	for (size_t i = 0; i < _bodyPositions.size(); ++i) {
		const std::pair<float, float> &pair = dynamic_cast<const Sprite *>(_cacheAssets[i].get())->getPosition();
		std::cout << pair.first << ", " << pair.second << std::endl;
		std::cout << dynamic_cast<const Sprite *>(_cacheAssets[i].get())->getTextureName() << std::endl;
	}
	std::cout << "Body:" << std::endl;
	for (const auto &pair : _bodyPositions)
		std::cout << pair.first << ", " << pair.second << std::endl;
}

unsigned int arc::Snake::size() const
{
	return static_cast<unsigned int>(_bodyPositions.size());
}

bool arc::Snake::isDead() const
{
	return _isDead;
}

arc::Snake::Direction arc::operator*(const arc::Snake::Direction &dir1, const arc::PlayerDirection &dir2)
{
	if (dir2 == PLAYER_NONE)
		return dir1;
	switch (dir1) {
	case arc::Snake::UP:
		return (dir2 == arc::PLAYER_RIGHT ? arc::Snake::RIGHT : arc::Snake::LEFT);
	case arc::Snake::RIGHT:
		return (dir2 == arc::PLAYER_RIGHT ? arc::Snake::DOWN : arc::Snake::UP);
	case arc::Snake::DOWN:
		return (dir2 == arc::PLAYER_RIGHT ? arc::Snake::LEFT : arc::Snake::RIGHT);
	case arc::Snake::LEFT:
		return (dir2 == arc::PLAYER_RIGHT ? arc::Snake::UP : arc::Snake::DOWN);
	default:
		throw "Snake direction is not known";
	}
}

std::ostream &arc::operator<<(std::ostream &stream, const arc::Snake::Direction &dir)
{
	if (dir == arc::Snake::UP)
		return stream << "UP";
	if (dir == arc::Snake::DOWN)
		return stream << "DOWN";
	if (dir == arc::Snake::LEFT)
		return stream << "LEFT";
	if (dir == arc::Snake::RIGHT)
		return stream << "RIGHT";
	return stream << "NOTHING";
}