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
#include "Position.hpp"

namespace arc {
	class Cell {
	public:
		enum STATE {
			WALKABLE,
			BORDER,
			TRAIL,
			NON_WALKABLE,
			QIX
		};

		explicit Cell(STATE state);

		void alterState(STATE state);
		STATE state() const;
		const Sprite &sprite() const;
		void setPosition(const std::pair<float, float> &pos);
		void setSize(const std::pair<float, float> &size);
	protected:
		STATE _state;
		Sprite _sprite;
		static const std::map<STATE, unsigned> _stateColor;
	};
}

#endif
