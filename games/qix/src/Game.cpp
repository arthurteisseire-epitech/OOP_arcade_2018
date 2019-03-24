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
	if (keys.find(UP) != keys.end())
		movePlayerUp();
	if (keys.find(DOWN) != keys.end())
		_player.moveDown();
	if (keys.find(LEFT) != keys.end())
		_player.moveLeft();
	if (keys.find(RIGHT) != keys.end())
		_player.moveRight();
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

void arc::Game::movePlayerUp()
{
	_player.moveUp();
}
