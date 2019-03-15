/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.hpp,
*/

#ifndef ARCADE_MAP_HPP
#define ARCADE_MAP_HPP


#include <string>
#include <vector>
#include "Snake.hpp"
#include "Food.hpp"

namespace arc {
	class Map {
	public:
		explicit Map(unsigned int size = 100);

		Food generateFood();

	protected:
		unsigned int _size;
		Snake _snake;
		Food _food;
	};
}

#endif //ARCADE_MAP_HPP
