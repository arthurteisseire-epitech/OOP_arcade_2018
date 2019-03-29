/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score.hpp
*/

#ifndef ARCADE_SCORE_HPP
#define ARCADE_SCORE_HPP

#include <string>

namespace arc {
	class Score {
	public:
		static void write(const std::string &gameName, const std::string &playerName, int score);
	private:
		static const std::string FILENAME;
	};
}

#endif
