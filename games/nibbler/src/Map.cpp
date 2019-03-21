/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include <random>
#include "MathUtils.hpp"
#include "Map.hpp"

#include <iostream>
arc::Map::Map(const pos_t &size) :
	_size(size),
	_snake(std::make_unique<Snake>(size / 2, 4, size)),
	_food(std::make_unique<Food>(pos_t{0, 0}, _size))
{
	generateFood();
}

void arc::Map::generateFood()
{
	std::random_device randomDevice;
	pos_t food_pos = {randomDevice() % _size.first, randomDevice() % _size.second};

	if (_snake->isInSnake(food_pos))
		return generateFood();
	_food->move(food_pos, _size);
}

void arc::Map::generateSprites(std::vector<std::reference_wrapper<arc::IComponent>> &vector) const
{
	std::vector<std::reference_wrapper<IComponent>> snake_parts = _snake->getParts();

	vector.insert(vector.end(), snake_parts.begin(), snake_parts.end());
	vector.emplace_back(_food->getSprite());
}

void arc::Map::updateSnake(PlayerDirection key)
{
	_snake->changeDirection(key);
}