/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler.cpp
*/

#include <memory>
#include <ctime>
#include "Nibbler.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

arc::IGame *gameEntryPoint()
{
	return new arc::Nibbler();
}

const float arc::Nibbler::_actionTime = 0.2;

arc::Nibbler::Nibbler() :
	_score(0),
	_size(50),
	_map({_size, _size}),
	_lastDir(PLAYER_NONE),
	_localDeltaTime(0)
{
	srand((unsigned)time(nullptr));
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::Nibbler::getComponents() const
{
	std::vector<std::reference_wrapper<const IComponent>> vec;
	IComponent *score = new Text(std::string("Score: ") + std::to_string(_score), std::pair<float, float>(0.1, 0.2),
	                             20);

	_map.generateSprites(vec);
	vec.emplace_back(*score);
	return vec;
}

void arc::Nibbler::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime,
                          const std::pair<unsigned int, unsigned int> &)
{
	getLastDirection(keys);
	updateTime(deltaTime);
	if (_localDeltaTime >= _actionTime) {
		_localDeltaTime = 0;
		_map.updateSnake(_lastDir, _score);
		_lastDir = PLAYER_NONE;
	}
}

bool arc::Nibbler::isRunning() const
{
	return !_map.isSnakeDead() && !_map.isFull();
}

void arc::Nibbler::updateTime(float time)
{
	_localDeltaTime += time;
}

void arc::Nibbler::getLastDirection(const std::map<arc::Key, arc::KeyState> &keys)
{
	if (keys.find(Key::LEFT) != keys.end() && keys.at(Key::LEFT) == PRESSED)
		_lastDir = PLAYER_LEFT;
	else if (keys.find(Key::RIGHT) != keys.end() && keys.at(Key::RIGHT) == PRESSED)
		_lastDir = PLAYER_RIGHT;
}