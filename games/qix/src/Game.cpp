/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Game.cpp
*/

#include "Game.hpp"

arc::IGame *gameEntryPoint()
{
	return new arc::Game();
}

arc::Game::Game() : _player(),
                    _map(10, 10)
{
}

void arc::Game::update(const std::map<arc::Key, arc::KeyState> &keys, float,
                       const std::pair<unsigned int, unsigned int> &)
{
	auto key = keys.find(UP);
	if (key != keys.end() && key->second == PRESSED) {
		_player.move(Player::UP);
	}

	key = keys.find(DOWN);
	if (key != keys.end() && key->second == PRESSED) {
		_player.move(Player::DOWN);
	}
}

bool arc::Game::isRunning() const
{
	return true;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Game::getComponents() const
{
	std::vector<std::reference_wrapper<const arc::IComponent>> wrapper;

	wrapper.emplace_back(_player.getSprite());
	return wrapper;
}
