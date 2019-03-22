/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler.hpp,
*/

#ifndef ARCADE_NIBBLER_HPP
#define ARCADE_NIBBLER_HPP

#include "IGame.hpp"
#include "Map.hpp"
#include "PlayerDirection.hpp"

namespace arc {
	class Nibbler : public IGame {
	public:
		Nibbler(int &ac, char *av[]);

		std::vector<std::reference_wrapper<const IComponent>> getComponents() const override;
		void update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime,
		            const std::pair<unsigned int, unsigned int> &windowSize) override;
		bool isRunning() const override;
	private:
		void updateTime(float time);

		unsigned int _score;
		unsigned int _size;
		Map _map;
		PlayerDirection _lastDir;
		float _localDeltaTime;
		static const float _actionTime;
		void getLastDirection(const std::map<Key, KeyState> &keys);
	};
}

extern "C" __attribute__((visibility("default"))) arc::IGame *gameEntryPoint(int &ac, char **av);

#endif
