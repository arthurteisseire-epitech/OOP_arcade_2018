/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cell.hpp
*/

#ifndef ARCADE_CELL_HPP
#define ARCADE_CELL_HPP

#include <map>
#include "Sprite.hpp"

namespace arc {
	class Cell {
	public:
		enum STATE {
			WALKABLE,
			BORDER,
			TRAIL,
			NON_WALKABLE
		};

		explicit Cell(STATE state);
		STATE state() const;
		Sprite &sprite();
	protected:
		STATE _state;
		Sprite _sprite;
		static const std::map<STATE, unsigned> _stateColor;
	};
}

#endif
