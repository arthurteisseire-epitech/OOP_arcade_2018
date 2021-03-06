/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IGame.hpp,
*/

#ifndef IGAME_HPP
#define IGAME_HPP

#include <vector>
#include <map>
#include "IComponent.hpp"
#include "Key.hpp"

namespace arc {
	class IGame {
	public:
		virtual ~IGame() = default;

		virtual bool isRunning() const = 0;
		virtual void update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime,
		                    const std::pair<unsigned int, unsigned int> &windowSize) = 0;
		virtual std::vector<std::reference_wrapper<const IComponent>> getComponents() const = 0;
		virtual int getScore() const = 0;
	};
}

#endif
