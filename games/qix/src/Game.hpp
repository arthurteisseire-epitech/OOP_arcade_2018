/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Game.hpp
*/

#ifndef ARCADE_GAME_HPP
#define ARCADE_GAME_HPP

#include <map>
#include <functional>
#include "IGame.hpp"
#include "Key.hpp"
#include "Player.hpp"
#include "Map.hpp"

namespace arc {
	class Game : public IGame {
	public:
		Game();
		std::vector<std::reference_wrapper<const IComponent>> getComponents() const override;
		void update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime,
		            const std::pair<unsigned int, unsigned int> &windowSize) override;
		bool isRunning() const override;
		void movePlayerUp();
	protected:
		Player _player;
		Map _map;
	};
}

extern "C" __attribute__((visibility("default"))) arc::IGame *gameEntryPoint();

#endif
