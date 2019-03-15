/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Snake.cpp
*/

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

const std::unordered_map<arc::Snake::Direction, pos_t> arc::Snake::_direction_map = {
	{UP, {0, -1}},
	{DOWN, {0, 1}},
	{RIGHT, {1, 0}},
	{LEFT, {-1, 0}}
};

arc::Snake::Snake(pos_t start_pos, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
		_body_positions.emplace_back(start_pos + pos_t{i, 0});
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