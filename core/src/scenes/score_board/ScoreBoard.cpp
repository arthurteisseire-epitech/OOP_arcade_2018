/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScoreBoard.cpp
*/

#include <algorithm>
#include "Score.hpp"
#include "ScoreBoard.hpp"

arc::ScoreBoard::ScoreBoard(const std::shared_ptr<arc::SharedData> &playerData) :
	Scene(playerData),
	_header("SCORE BOARD", {0.5, 0.1}, 50),
	_bestScore("BEST SCORES : ", {0.2, 0.2}, 35)
{
	_rows = Score::read();
	std::sort(_rows.begin(), _rows.end(), [](auto &pair1, auto &pair2) {
		return pair1.first > pair2.first;
	});
	createTexts();
}

void arc::ScoreBoard::update(const std::map<arc::Key, arc::KeyState> &, float)
{
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::ScoreBoard::getComponents() const
{
	std::vector<std::reference_wrapper<const arc::IComponent>> wrapper;

	wrapper.reserve(_gameNames.size() + _playerNames.size() + _scores.size() + 2);
	for (const auto &gameName : _gameNames)
		wrapper.emplace_back(gameName);

	for (const auto &playerName : _playerNames)
		wrapper.emplace_back(playerName);

	for (const auto &score : _scores)
		wrapper.emplace_back(score);

	wrapper.emplace_back(_header);
	wrapper.emplace_back(_bestScore);
	return wrapper;
}

arc::SCENE arc::ScoreBoard::nextScene(const std::map<arc::Key, arc::KeyState> &) const
{
	return SCOREBOARD;
}

void arc::ScoreBoard::createTexts()
{
	int i = 0;
	float y = 0.3f;

	for (const auto &row : _rows) {
		_gameNames.emplace_back(row.second.first, std::pair<float, float>(0.2, y), 30);
		_playerNames.emplace_back(row.second.second, std::pair<float, float>(0.3, y), 30);
		_scores.emplace_back(std::to_string(row.first), std::pair<float, float>(0.5, y), 30);
		y += 0.05;
		if (i > 8)
			break;
		++i;
	}
}
