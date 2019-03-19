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
#include "IComponent.hpp"
#include "Snake.hpp"
#include "Food.hpp"

namespace arc {
	class Map {
	public:
		explicit Map(const pos_t &size = {100, 100});

		Food &generateFood();
		void generateSprites(std::vector<std::reference_wrapper<IComponent>> &vector) const;
	protected:
		pos_t _size;
		Snake _snake;
		Food _food;
	};
}

#endif //ARCADE_MAP_HPP
