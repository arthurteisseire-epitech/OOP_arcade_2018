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
                    _map(20, 20)
{
}

void arc::Game::update(const std::map<arc::Key, arc::KeyState> &keys, float,
                       const std::pair<unsigned int, unsigned int> &)
{
	if (keys.find(UP) != keys.end())
		movePlayerUp();
}

bool arc::Game::isRunning() const
{
	return true;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Game::getComponents() const
{
	return std::vector<std::reference_wrapper<const arc::IComponent>>();
}

void arc::Game::movePlayerUp()
{
	_player.moveUp();
}
