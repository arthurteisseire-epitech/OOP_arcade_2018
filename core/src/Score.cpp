/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score.cpp
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "Score.hpp"

const std::string arc::Score::FILENAME = "scores.txt";

void arc::Score::write(const std::string &gameName, const std::string &playerName, int score)
{
	std::ofstream file;

	file.open(FILENAME, std::ios::app);
	file << gameName << " " << playerName << " " << score << std::endl;
	file.close();
}

std::map<int, std::pair<std::string, std::string>> arc::Score::read()
{
	std::ifstream file(FILENAME);
	std::map<int, std::pair<std::string, std::string>> scores;
	std::string line;

	if (!file.fail())
		while (std::getline(file, line))
			addRow(scores, line);
	return scores;
}

void arc::Score::addRow(std::map<int, std::pair<std::string, std::string>> &scores, std::string &line)
{
	try {
		scores.emplace(arc::Score::nextRow(line));
	} catch (const std::exception &e) {
	}
}

std::pair<int, std::pair<std::string, std::string>> arc::Score::nextRow(std::string &line)
{
	std::string gameName;
	std::string playerName;
	std::string score;
	int s;

	gameName = line.substr(0, line.find(' '));
	line = line.substr(line.find(' ') + 1);

	playerName = line.substr(0, line.find(' '));
	line = line.substr(line.find(' ') + 1);

	score = line.substr(0, line.find('\n'));
	s = std::stoi(score);

	if (playerName.length() != 3)
		throw std::exception();
	return {s, {gameName, playerName}};
}
