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
#include <memory>
#include "Sprite.hpp"
#include "Pos.hpp"
#include "PlayerDirection.hpp"

#ifndef PATH_TO_ASSETS
#define PATH_TO_ASSETS	"./games/nibbler/assets/sprites/"
#endif

typedef std::vector<pos_t> body_t;

namespace arc {
	class Snake {
	public:
		enum Direction {
			UP, DOWN, LEFT, RIGHT
		};

		explicit Snake(const pos_t &start_pos, unsigned int size, const pos_t &map_size);

		void eat();
		void moveBody(const Direction &direction);
		bool isInSnake(const pos_t &pos) const;
		std::vector<std::reference_wrapper<IComponent>>	getParts() const;
		void changeDirection(arc::PlayerDirection playerDir);
	protected:
		std::pair<unsigned int, unsigned int> findTailDirection();
		Direction findHeadDir();

		body_t _bodyPositions;
		static const std::unordered_map<Direction, pos_t> _directionMap;
		static const std::unordered_map<Direction, std::vector<std::string>> _snakeAssetsMap;
		std::vector<std::unique_ptr<IComponent>> _cacheAssets;

	private:
		void
		append_sprite(const pos_t &pos_res, std::unique_ptr<arc::Sprite> &actual_sprite, const pos_t &size);
	};

	Snake::Direction operator*(const Snake::Direction &, const PlayerDirection &);
}

#endif
