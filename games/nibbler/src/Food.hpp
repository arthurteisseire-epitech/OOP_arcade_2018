/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Food.hpp
*/

#ifndef ARCADE_FOOD_HPP
#define ARCADE_FOOD_HPP

#ifndef POS_T
#define POS_T
#include <utility>
typedef std::pair<unsigned int, unsigned int> pos_t;
#endif

namespace arc {
	class Food {
	public:
		explicit Food(const pos_t &position);

		static const unsigned int value;
	protected:
		pos_t _pos;
	};
}

#endif //ARCADE_FOOD_HPP
