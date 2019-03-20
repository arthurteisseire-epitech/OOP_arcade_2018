/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Snake.cpp
*/

#include "Sprite.hpp"
#include "Snake.hpp"
#include "MathUtils.hpp"

const std::unordered_map<arc::Snake::Direction, pos_t> arc::Snake::_directionMap = {{UP, {0, -1}}, {DOWN, {0, 1}},
	{RIGHT, {1, 0}}, {LEFT, {-1, 0}}};

const std::unordered_map<arc::Snake::Direction, std::vector<std::string>> arc::Snake::_snakeAssetsMap = {
	{UP, {"snake_head_up.png", "snake_middle_vertical.png", "snake_tail_up.png"}},
	{DOWN, {"snake_head_down.png", "snake_middle_vertical.png", "snake_tail_down.png"}},
	{RIGHT, {"snake_head_right.png", "snake_middle_horizontal.png", "snake_tail_right.png"}},
	{LEFT, {"snake_head_left.png", "snake_middle_horizontal.png", "snake_tail_left.png"}}};

void arc::Snake::append_sprite(const pos_t &pos_res, std::unique_ptr<arc::Sprite> &actual_sprite, const pos_t &size)
{
	actual_sprite->setPosition(pos_res / size);
	actual_sprite->setSize(pos_t{1.0, 1.0} / size);
	_cacheAssets.emplace_back(std::move(actual_sprite));
}

arc::Snake::Snake(const pos_t &start_pos, unsigned int size, const pos_t &map_size)
{
	pos_t pos_res;
	std::unique_ptr<Sprite> actual_sprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(LEFT)[0]);

	append_sprite(start_pos, actual_sprite, map_size);
	_bodyPositions.emplace_back(start_pos + pos_t{size - 1, 0});
	for (unsigned int i = 1; i < size - 1; ++i) {
		pos_res = start_pos + pos_t{i, 0};
		_bodyPositions.emplace_back(pos_res);
		actual_sprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(LEFT)[1]);
		append_sprite(pos_res, actual_sprite, map_size);
	}
	_bodyPositions.emplace_back(start_pos + pos_t{size - 1, 0});
	actual_sprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snakeAssetsMap.at(LEFT)[2]);
	append_sprite(pos_res + pos_t{1, 0}, actual_sprite, map_size);
}

void arc::Snake::eat()
{
	_bodyPositions.push_back(_bodyPositions.back() - findTailDirection());
}

std::pair<unsigned int, unsigned int> arc::Snake::findTailDirection()
{
	unsigned long size = _bodyPositions.size();

	return _bodyPositions[size - 2] - _bodyPositions[size - 1];
}

void arc::Snake::moveBody(const arc::Snake::Direction &direction)
{
	_bodyPositions.insert(_bodyPositions.begin(), _bodyPositions.front() + _directionMap.at(direction));
	_bodyPositions.pop_back();
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

	moveBody(snakeDir * playerDir);
}

arc::Snake::Direction arc::Snake::findHeadDir()
{
	pos_t pos_dir = _bodyPositions[0] - _bodyPositions[1];

	if (pos_dir.first != 0)
		return pos_dir.first == 1 ? RIGHT : LEFT;
	if (pos_dir.second != 0)
		return pos_dir.second == 1 ? DOWN : UP;
	return DOWN;
}

arc::Snake::Direction arc::operator*(const arc::Snake::Direction &dir1, const arc::PlayerDirection &dir2)
{
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
		return (arc::Snake::DOWN);
	}
}