/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Map.hpp
*/

#ifndef ARCADE_MAP_HPP
#define ARCADE_MAP_HPP

#include <vector>
#include "Position.hpp"
#include "Cell.hpp"

namespace arc {
	class Map {
	public:
		explicit Map(int width, int height);
		~Map();

		int width() const;
		int height() const;
		bool in(const Position &pos) const;
		bool inBorder(const Position &pos) const;
		bool inWalkable(const Position &pos) const;
		void trail(const Position &pos);
		void transformTrailToBorder();
		std::vector<std::reference_wrapper<const IComponent>> getSprites() const;
	protected:
		int _width;
		int _height;
		std::vector<std::vector<Cell>> _cells;
		std::vector<std::reference_wrapper<const IComponent>> _sprites;
	};
}

#endif
