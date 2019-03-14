/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Snake.hpp,
*/

#ifndef ARCADE_SNAKE_HPP
#define ARCADE_SNAKE_HPP

#include <vector>

typedef std::pair<unsigned int, unsigned int> pos_t;
typedef std::vector<pos_t> body_t;

namespace arc {
	class Snake {
	public:
		Snake(pos_t start_pos, unsigned int size = 4);

		void eat();

	protected:
		std::pair<unsigned int, unsigned int> find_tail_direction();

		body_t _body_positions;
	};
}

#endif //ARCADE_SNAKE_HPP
