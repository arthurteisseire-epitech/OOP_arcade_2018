/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.cpp
*/

#include "Map.hpp"

arc::Map::Map(int width, int height) : _width(width),
                                       _height(height),
                                       _cells()
{
	_cells.reserve((size_t)width * height);
	for (int y = 0; y < height; ++y)
		for (int x = 0; x < width; ++x)
			_cells.emplace_back(x);
}

arc::Map::~Map()
{
	_cells.clear();
}

