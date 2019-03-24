/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.hpp
*/

#ifndef ARCADE_PLAYER_HPP
#define ARCADE_PLAYER_HPP

#include "Sprite.hpp"

namespace arc {
	class Player {
	public:
		Player();

		void moveDown();
		void moveUp();
		void moveRight();
		void moveLeft();
		const Sprite &getSprite() const;
	protected:
		Sprite _sprite;
		int _x;
		int _y;
	};
}

#endif
