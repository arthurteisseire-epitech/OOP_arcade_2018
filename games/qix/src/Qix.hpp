/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Qix.hpp
*/

#ifndef ARCADE_QIX_HPP
#define ARCADE_QIX_HPP

#include "Position.hpp"

namespace arc {
	class Qix {
	public:
		explicit Qix(const arc::Position &pos, unsigned int size);
		const Position &position() const;
		void move(const Position &direction);
		unsigned int radius() const;

	private:
		Position _pos;
		unsigned int _size;
	};
}

#endif
