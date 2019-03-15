/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp,
*/

#include <random>
#include "Map.hpp"

arc::Map::Map(unsigned int size) :
	_size(size),
	_snake({size / 2, size / 2}),
	_food(generateFood())
{
}

arc::Food arc::Map::generateFood()
{
	std::random_device randomDevice;
	pos_t food_pos = {randomDevice() % _size, randomDevice() % _size};

	_food = Food(food_pos);
	if (!_snake.isFoodNotInSnake(food_pos))
		generateFood();
	return _food;
}

void arc::Map::generateSprites(std::vector<std::reference_wrapper<arc::IComponent>> &vector) const
{
	std::vector<std::reference_wrapper<IComponent>> snake_parts = _snake.getParts();

	vector.insert(vector.end(), snake_parts.begin(), snake_parts.end());
}
