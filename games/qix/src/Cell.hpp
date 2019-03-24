/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cell.hpp
*/

#ifndef ARCADE_CELL_HPP
#define ARCADE_CELL_HPP

namespace arc {
	class Cell {
	public:
		enum STATES {
			WALKABLE,
			NON_WALKABLE,
		};

		Cell();
	protected:
		STATES _state;
	};
}

#endif
