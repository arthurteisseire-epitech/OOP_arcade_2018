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
#include <map>
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

		explicit Snake(const pos_t &startPos, unsigned int size, const pos_t &mapSize);

		void eat();
		void moveBody(const arc::Snake::Direction &direction, bool changeDir);
		bool isInSnake(const pos_t &pos) const;
		std::vector<std::reference_wrapper<IComponent>>	getParts() const;
		void changeDirection(arc::PlayerDirection playerDir);
	protected:
		pos_t findTailPosDirection();
		Direction findHeadDir();

		body_t _bodyPositions;
		static const std::unordered_map<Direction, pos_t> _directionMap;
		static const std::map<pos_t, Direction> _directionPosMap;
		static const std::unordered_map<Direction, std::vector<std::string>> _assetsMap;
		static const std::map<std::pair<Direction, Direction>, std::string> _curvedAssets;
		std::vector<std::unique_ptr<IComponent>> _cacheAssets;
	private:
		void append_sprite(const pos_t &posRes, std::unique_ptr<arc::Sprite> &actualSprite, const pos_t &size);
		void turnHead(const arc::Snake::Direction &direction, const std::pair<float, float> &headPos,
					      const Direction &lastDirection);
		const std::string &findCurveSnake(const Direction &direction, const Direction &lastDirection) const;
		std::pair<float, float> findNewPos(const pos_t &snakeDirection, const std::pair<float, float> &headPos) const;
		void updateAllBody(const Direction &direction, const std::pair<float, float> &headPos, bool changeDir,
						   const Direction &lastDirection);
		void moveTailToNeck(const Direction &direction, const Direction &lastDirection, bool changeDir);
		void createNeckAsset(const Direction &direction, const Direction &lastDirection, bool changeDir);
		void updateSprites(const Direction &direction, bool changeDir, const Direction &lastDirection);
		void createNewTail();
		void printSnakePos();

		pos_t _mapSize;
	};

	Snake::Direction operator*(const Snake::Direction &, const PlayerDirection &);
	std::ostream &operator<<(std::ostream &stream, const Snake::Direction &dir);
}

#endif
