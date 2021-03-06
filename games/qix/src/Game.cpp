/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Game.cpp
*/

#include "Game.hpp"

const std::map<arc::Key, arc::Player::DIRECTION> arc::Game::_keyDir =
	{
		{UP,    Player::UP},
		{DOWN,  Player::DOWN},
		{LEFT,  Player::LEFT},
		{RIGHT, Player::RIGHT}
	};

arc::IGame *gameEntryPoint()
{
	return new arc::Game();
}

arc::Game::Game() :
	_map({101, 101}),
	_player(_map)
{
}

void arc::Game::update(const std::map<arc::Key, arc::KeyState> &keys, float dTime,
                       const std::pair<unsigned int, unsigned int> &)
{
	static float locDTime = 0;

	for (const auto &keyDir : _keyDir)
		updatePlayer(keys, dTime, locDTime, keyDir);
	_map.updateQix(dTime);
}

void arc::Game::updatePlayer(const std::map<arc::Key, arc::KeyState> &keys, float dTime, float &locDTime,
			const std::pair<const arc::Key, arc::Player::DIRECTION> &keyDir)
{
	auto key = keys.find(keyDir.first);
	if (key != keys.end()) {
			if (key->second == arc::PRESSED)
				_player.move(keyDir.second);
			if (key->second == arc::HOLD)
				handleHold(dTime, locDTime, keyDir);
			else
				locDTime = 0;
		}
}

void
arc::Game::handleHold(float dTime, float &locDTime, const std::pair<const arc::Key, arc::Player::DIRECTION> &keyDir)
{
	locDTime += dTime;
	if (locDTime > 0.2) {
		_player.move(keyDir.second);
		locDTime = 0;
	}
}

bool arc::Game::isRunning() const
{
	return _map.findPercentCovered() <= 75 && _map.isPlayerAlive();
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Game::getComponents() const
{
	std::vector<std::reference_wrapper<const arc::IComponent>> wrapper = _map.getSprites();

	wrapper.emplace_back(_player.getSprite());
	return wrapper;
}

int arc::Game::getScore() const
{
	return _map.findPercentCovered();
}
