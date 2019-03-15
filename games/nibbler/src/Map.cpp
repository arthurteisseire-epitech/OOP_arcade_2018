/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp,
*/

#include "Map.hpp"

arc::Map::Map(unsigned int size) :
	_size(size),
	_snake({size / 2, size / 2}),
	_food(generateFood())
{
}

arc::Food arc::Map::generateFood()
{

}
