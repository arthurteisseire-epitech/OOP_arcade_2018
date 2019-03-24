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
	protected:
		void moveDown();
		void moveUp();

		int _x;
		int _y;
	};
}

#endif
