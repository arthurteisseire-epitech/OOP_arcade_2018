/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.hpp
*/

#ifndef ARCADE_PLAYER_HPP
#define ARCADE_PLAYER_HPP

namespace arc {
	class Player {
	public:
		Player();

		void moveDown();
		void moveUp();
		void moveRight();
		void moveLeft();
	protected:
		int _x;
		int _y;
	};
}

#endif
