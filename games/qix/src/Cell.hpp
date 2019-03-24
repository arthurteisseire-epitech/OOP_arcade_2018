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
		enum STATE {
			WALKABLE,
			NON_WALKABLE,
			BORDER
		};

		Cell(STATE state);
		STATE state() const;
	protected:
		STATE _state;
	};
}

#endif
