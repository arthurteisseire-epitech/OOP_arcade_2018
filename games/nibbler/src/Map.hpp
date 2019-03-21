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
#include <Key.hpp>
#include "IComponent.hpp"
#include "Snake.hpp"
#include "Food.hpp"

namespace arc {
	class Map {
	public:
		explicit Map(const pos_t &size = {100, 100});

		void generateFood();
		void generateSprites(std::vector<std::reference_wrapper<IComponent>> &vector) const;
		void updateSnake(arc::PlayerDirection key);
	protected:
		pos_t _size;
		std::unique_ptr<Snake>_snake;
		std::unique_ptr<Food> _food;
	};
}

#endif
