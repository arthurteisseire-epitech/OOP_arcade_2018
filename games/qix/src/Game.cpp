/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Game.cpp
*/

#include "Game.hpp"

const std::map<arc::Key, arc::Player::DIRECTION> arc::Game::_keyDir = {
	{UP, Player::UP},
	{DOWN, Player::DOWN},
	{LEFT, Player::LEFT},
	{RIGHT, Player::RIGHT},
};

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
	for (const auto &keyDir : _keyDir) {
		auto key = keys.find(keyDir.first);
		if (key != keys.end() && key->second == PRESSED)
			_player.move(keyDir.second);
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
