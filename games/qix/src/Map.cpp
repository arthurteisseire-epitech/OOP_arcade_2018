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
	_cells.reserve(static_cast<size_t>(height));
	for (int y = 0; y < height; ++y) {
		_cells.emplace_back(std::vector<Cell>());
		_cells[y].reserve(static_cast<size_t>(width));
		for (int x = 0; x < width; ++x)
			_cells[y].emplace_back(Cell());
	}
}

arc::Map::~Map()
{
	_cells.clear();
}

int arc::Map::width() const
{
	return _width;
}

int arc::Map::height() const
{
	return _height;
}

