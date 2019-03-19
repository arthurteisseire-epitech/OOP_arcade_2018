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
		void move_body(const Direction &direction);
		bool isInSnake(const pos_t &pos) const;
		std::vector<std::reference_wrapper<IComponent>>	getParts() const;
	protected:
		std::pair<unsigned int, unsigned int> find_tail_direction();

		body_t _body_positions;
		static const std::unordered_map<Direction, pos_t> _direction_map;
		static const std::unordered_map<Direction, std::vector<std::string>> _snake_assets_map;
		std::vector<std::unique_ptr<IComponent>> _cache_assets;
//		Direction find_head_direction() const;

	private:
		void
		append_sprite(const pos_t &pos_res, std::unique_ptr<arc::Sprite> &actual_sprite, const pos_t &size);
	};
}

#endif
