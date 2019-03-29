/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score.hpp
*/

#ifndef ARCADE_SCORE_HPP
#define ARCADE_SCORE_HPP

#include <map>

namespace arc {
	class Score {
	public:
		static void write(const std::string &gameName, const std::string &playerName, int score);
		static std::map<int, std::pair<std::string, std::string>> read();
	private:
		static std::pair<int, std::pair<std::string, std::string>> nextRow(std::string &line);
		static void addRow(std::map<int, std::pair<std::string, std::string>> &scores, std::string &line);

		static const std::string FILENAME;
	};
}

#endif
