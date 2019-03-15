/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Snake.cpp
*/

#include "Sprite.hpp"
#include "Snake.hpp"

template<typename T>
std::pair<T, T> operator+(const std::pair<T, T> &p1, const std::pair<T, T> &p2)
{
	return {p1.first + p2.first, p1.second + p2.second};
}

template<typename T>
std::pair<T, T> operator-(const std::pair<T, T> &p1, const std::pair<T, T> &p2)
{
	return {p1.first - p2.first, p1.second - p2.second};
}

std::pair<float, float> operator/(const std::pair<unsigned int, unsigned int> &p1, const unsigned int &div)
{
	return {(float)p1.first / div, (float)p1.second / div};
}

const std::unordered_map<arc::Snake::Direction, pos_t> arc::Snake::_direction_map = {
	{UP,    {0,  -1}},
	{DOWN,  {0,  1}},
	{RIGHT, {1,  0}},
	{LEFT,  {-1, 0}}
};

const std::unordered_map<arc::Snake::Direction, std::vector<std::string>> arc::Snake::_snake_assets_map= {
	{UP,    {"snake_head_up.png", "snake_middle_vertical.png", "snake_tail_up.png"}},
	{DOWN,  {"snake_head_down.png", "snake_middle_vertical.png", "snake_tail_down.png"}},
	{RIGHT, {"snake_head_right.png", "snake_middle_horizontal.png", "snake_tail_right.png"}},
	{LEFT,  {"snake_head_left.png", "snake_middle_horizontal.png", "snake_tail_left.png"}}
};


void arc::Snake::append_sprite(const pos_t &pos_res, std::unique_ptr<arc::Sprite> &actual_sprite)
{
	actual_sprite->setPosition(pos_res / (pos_res.second * 2));
	actual_sprite->setSize({1.0 / (pos_res.second * 2), 1.0 / (pos_res.second * 2)});
	_cache_assets.emplace_back(std::move(actual_sprite));
}

arc::Snake::Snake(pos_t start_pos, unsigned int size)
{
	pos_t pos_res;
	std::unique_ptr<Sprite> actual_sprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snake_assets_map.at(LEFT)[0]);

	append_sprite(start_pos, actual_sprite);
	_body_positions.emplace_back(start_pos + pos_t{size - 1, 0});
	for (unsigned int i = 1; i < size - 1; ++i) {
		pos_res = start_pos + pos_t{i, 0};
		_body_positions.emplace_back(pos_res);
		actual_sprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snake_assets_map.at(LEFT)[1]);
		append_sprite(pos_res, actual_sprite);
	}
	_body_positions.emplace_back(start_pos + pos_t{size - 1, 0});
	actual_sprite = std::make_unique<Sprite>(PATH_TO_ASSETS + _snake_assets_map.at(LEFT)[2]);
	append_sprite(pos_res + pos_t{1, 0}, actual_sprite);
}

void arc::Snake::eat()
{
	_body_positions.push_back(_body_positions.back() - find_tail_direction());
}

std::pair<unsigned int, unsigned int> arc::Snake::find_tail_direction()
{
	unsigned long size = _body_positions.size();

	return _body_positions[size - 2] - _body_positions[size - 1];
}

void arc::Snake::move_body(const arc::Snake::Direction &direction)
{
	_body_positions.insert(_body_positions.begin(), _body_positions.front() + _direction_map.at(direction));
	_body_positions.pop_back();
}

bool arc::Snake::isFoodNotInSnake(const pos_t &fruit_pos) const
{
	for (auto &snake_part : _body_positions)
		if (snake_part == fruit_pos)
			return (false);
	return true;
}

std::vector<std::reference_wrapper<arc::IComponent>> arc::Snake::getParts() const
{
	std::vector<std::reference_wrapper<IComponent>> vec;

	for (const std::unique_ptr<IComponent> &asset : _cache_assets)
		vec.emplace_back(*asset);
	return vec;
}