/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Snake.hpp,
*/

#ifndef ARCADE_SNAKE_HPP
#define ARCADE_SNAKE_HPP

#include <vector>
#include <unordered_map>

#ifndef POS_T
#define POS_T
typedef std::pair<unsigned int, unsigned int> pos_t;
#endif

typedef std::vector<pos_t> body_t;

namespace arc {
	class Snake {
	public:
		enum Direction {
			UP, DOWN, LEFT, RIGHT
		};

		explicit Snake(pos_t start_pos, unsigned int size = 4);

		void eat();
		void move_body(const Direction &direction);
		bool isFoodNotInSnake(const pos_t &fruit_pos) const;
	protected:
		std::pair<unsigned int, unsigned int> find_tail_direction();

		body_t _body_positions;
		static const std::unordered_map<Direction, pos_t> _direction_map;
	};
}

#endif //ARCADE_SNAKE_HPP
