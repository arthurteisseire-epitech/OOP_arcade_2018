/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Player.hpp
*/

#ifndef ARCADE_PLAYER_HPP
#define ARCADE_PLAYER_HPP

#include <functional>
#include "Position.hpp"
#include "Sprite.hpp"
#include "Map.hpp"

namespace arc {
	class Player {
	public:
		enum DIRECTION {
			UP,
			DOWN,
			RIGHT,
			LEFT
		};

		explicit Player(Map &map);

		void move(DIRECTION dir);
		const Sprite &getSprite() const;

	protected:
		Sprite _sprite;
		Position _pos;
		Map &_map;

	private:
		void moveInDirection(const arc::Player::DIRECTION &dir);
	};

	Position &operator+=(Position &pos, Player::DIRECTION dir);
	Position operator+(const Position &pos, Player::DIRECTION dir);
	bool operator==(const Position &pos1, const Position &pos2);
}

#endif
