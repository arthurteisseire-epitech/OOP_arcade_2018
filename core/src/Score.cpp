/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score.cpp
*/

#include <fstream>
#include "Score.hpp"

const std::string arc::Score::FILENAME = "scores.txt";

void arc::Score::write(const std::string &gameName, const std::string &playerName, int score)
{
	std::ofstream file;

	file.open(FILENAME, std::ios::app);
	file << gameName << " " << playerName << " " << score << std::endl;
	file.close();
}
