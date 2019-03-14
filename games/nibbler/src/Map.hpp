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

namespace arc {
	class Map {
	public:
		explicit Map(unsigned int size = 100);

	private:
		unsigned int _size;
	};
}

#endif //ARCADE_MAP_HPP
