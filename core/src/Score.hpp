/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score.hpp
*/

#ifndef ARCADE_SCORE_HPP
#define ARCADE_SCORE_HPP

#include <string>
#include <vector>

namespace arc {
	class Score {
	public:
		static void write(const std::string &gameName, const std::string &playerName, int score);
		static std::vector<std::pair<int, std::pair<std::string, std::string>>> read();
	private:
		static std::pair<int, std::pair<std::string, std::string>> nextRow(std::string &line);
		static void addRow(std::vector<std::pair<int, std::pair<std::string, std::string>>> &scores, std::string &line);

		static const std::string FILENAME;
	};
}

#endif
