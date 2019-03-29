/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScoreBoard.cpp
*/

#include "ScoreBoard.hpp"

arc::ScoreBoard::ScoreBoard(const std::shared_ptr<arc::SharedData> &playerData) :
	Scene(playerData)
{
	_rows.emplace(0, std::make_pair<std::string, std::string>("Gamename", "PlayerName"));
	_rows.emplace(10, std::make_pair<std::string, std::string>("hello", "hdddddddddddddddddddddd"));
	createTexts();
}

void arc::ScoreBoard::update(const std::map<arc::Key, arc::KeyState> &, float)
{
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::ScoreBoard::getComponents() const
{
	std::vector<std::reference_wrapper<const arc::IComponent>> wrapper;

	for (const auto &gameName : _gameNames)
		wrapper.emplace_back(gameName);

	for (const auto &playerName : _playerNames)
		wrapper.emplace_back(playerName);

	for (const auto &score : _scores)
		wrapper.emplace_back(score);

	return wrapper;
}

arc::SCENE arc::ScoreBoard::nextScene(const std::map<arc::Key, arc::KeyState> &keys) const
{
	return SCOREBOARD;
}

void arc::ScoreBoard::createTexts()
{
	float y = 0.3f;

	for (const auto &row : _rows) {
		_gameNames.emplace_back(row.second.first, std::pair<float, float>(0.4, y), 30);
		_playerNames.emplace_back(row.second.second, std::pair<float, float>(0.6, y), 30);
		_scores.emplace_back(std::to_string(row.first), std::pair<float, float>(0.8, y), 30);
		y += 0.05;
	}
}
