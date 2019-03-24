/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.hpp
*/

#ifndef ARCADE_MAP_HPP
#define ARCADE_MAP_HPP

#include <string>

namespace arc {
	class Map {
	public:
		explicit Map(int width, int height);
	protected:
		int _width;
		int _height;
	};
}

#endif
