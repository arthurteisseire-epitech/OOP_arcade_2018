/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Food.hpp
*/

#ifndef ARCADE_FOOD_HPP
#define ARCADE_FOOD_HPP


#include <string>
#include <memory>
#include "Sprite.hpp"
#include "Pos.hpp"

#ifndef PATH_TO_ASSETS
#define PATH_TO_ASSETS	"./games/nibbler/assets/sprites/"
#endif

namespace arc {
	class Food {
	public:
		explicit Food(const pos_t &position, const pos_t &size);

		std::reference_wrapper<ISprite> getSprite() const;
		void move(const pos_t &pos, const pos_t &size);

		static const unsigned int value;
	protected:
		pos_t _pos;
		const std::unique_ptr<Sprite> _sprite;
	};
}

#endif
