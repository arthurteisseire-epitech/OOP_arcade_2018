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

const std::unordered_map<arc::Snake::Direction, std::vector<std::string>> arc::Snake::_snakeAssetsMap = {
	{UP, {"snake_head_up.png", "snake_middle_vertical.png", "snake_tail_up.png"}},
	{DOWN, {"snake_head_down.png", "snake_middle_vertical.png", "snake_tail_down.png"}},
	{RIGHT, {"snake_head_right.png", "snake_middle_horizontal.png", "snake_tail_right.png"}},
	{LEFT, {"snake_head_left.png", "snake_middle_horizontal.png", "snake_tail_left.png"}}};

arc::Snake::Snake(const pos_t &startPos, unsigned int size, const pos_t &mapSize) : _mapSize(50, 50)
{
	pos_t posRes;
	std::unique_ptr<Sprite> actualSprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(LEFT)[0]);

	append_sprite(startPos, actualSprite, mapSize);
	_bodyPositions.emplace_back(startPos + pos_t{size - 1, 0});
	for (unsigned int i = 1; i < size - 1; ++i) {
		posRes = startPos + pos_t{i, 0};
		_bodyPositions.emplace_back(posRes);
		actualSprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(LEFT)[1]);
		append_sprite(posRes, actualSprite, mapSize);
	}
	_bodyPositions.emplace_back(startPos + pos_t{size - 1, 0});
	actualSprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(LEFT)[2]);
	append_sprite(posRes + pos_t{1, 0}, actualSprite, mapSize);
}

void arc::Snake::append_sprite(const pos_t &posRes, std::unique_ptr<arc::Sprite> &actualSprite, const pos_t &size)
{
	actualSprite->setPosition(posRes / size);
	actualSprite->setSize(pos_t{1.0, 1.0} / size);
	_cacheAssets.emplace_back(std::move(actualSprite));
}

void arc::Snake::eat()
{
	_bodyPositions.push_back(_bodyPositions.back() - findTailDirection());
}

pos_t arc::Snake::findTailDirection()
{
	unsigned long size = _bodyPositions.size();

	return _bodyPositions[size - 2] - _bodyPositions[size - 1];
}

void arc::Snake::moveBody(const arc::Snake::Direction &direction, bool changeDir)
{
	const pos_t &snakeDirection = _directionMap.at(direction);

	_bodyPositions.insert(_bodyPositions.begin(), _bodyPositions.front() + snakeDirection);
	_bodyPositions.pop_back();
	updateSprites(direction, changeDir);
}

void arc::Snake::updateSprites(const Direction &direction, bool changeDir)
{
	pos_t snakeDirection = _directionMap.at(direction);
	const std::pair<float, float> &headPos = dynamic_cast<Sprite *>(_cacheAssets[0].get())->getPosition();
	std::pair<float, float> newPos = {headPos.first + (float)snakeDirection.first / _mapSize.first,
		headPos.second + (float)snakeDirection.second / _mapSize.second};
	std::pair<float, float> tmpPos;

	if (changeDir)
		_cacheAssets[0] = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(direction)[0],
			pos_t{1.0, 1.0} / _mapSize, headPos);
	for (size_t i = 0; i < _bodyPositions.size(); ++i) {
		tmpPos = dynamic_cast<Sprite *>(_cacheAssets[i].get())->getPosition();;
		dynamic_cast<Sprite *>(_cacheAssets[i].get())->setPosition(newPos);
		newPos = tmpPos;
	}
}

bool arc::Snake::isInSnake(const pos_t &pos) const
{
	for (auto &snake_part : _bodyPositions)
		if (snake_part == pos)
			return true;
	return false;
}

std::vector<std::reference_wrapper<arc::IComponent>> arc::Snake::getParts() const
{
	std::vector<std::reference_wrapper<IComponent>> vec;

	for (const std::unique_ptr<IComponent> &asset : _cacheAssets)
		vec.emplace_back(*asset);
	return vec;
}

void arc::Snake::changeDirection(arc::PlayerDirection playerDir)
{
	Direction snakeDir = findHeadDir();

	std::cout << snakeDir * playerDir << std::endl;
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