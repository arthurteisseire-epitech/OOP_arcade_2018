/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.hpp
*/

#ifndef ARCADE_PLAYER_HPP
#define ARCADE_PLAYER_HPP

#include <functional>
#include "Sprite.hpp"

namespace arc {
	class Player {
	public:
		struct Position {
			Position(int x, int y) : x(x), y(y) {}
			int x;
			int y;
		};
		enum DIRECTION {
			UP,
			DOWN,
			RIGHT,
			LEFT
		};

		Player();

		void move(DIRECTION dir);
		const Sprite &getSprite() const;

	protected:
		Sprite _sprite;
		Position _pos;
	};

	Player::Position &operator+=(Player::Position &pos, Player::DIRECTION dir);
	bool operator==(const Player::Position &pos1, const Player::Position &pos2);
}

#endif
