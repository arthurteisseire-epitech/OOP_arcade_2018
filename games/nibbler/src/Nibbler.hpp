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

namespace arc {
	class Nibbler : public IGame {
	public:
		Nibbler(int &ac, char *av[]);

		std::vector<std::reference_wrapper<IComponent>> getComponents() const override;
		void update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime) override;
		bool isRunning() const override;
	private:
		unsigned int _score;
		unsigned int _size;
		Map _map;
	};
}

extern "C" __attribute__((visibility("default"))) arc::IGame *entryPoint(int &ac, char *av[]);

#endif
