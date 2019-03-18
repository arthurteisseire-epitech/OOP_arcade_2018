/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Row.hpp
*/

#ifndef ARCADE_ROW_HPP
#define ARCADE_ROW_HPP

#include <string>
#include <vector>
#include <memory>
#include "Text.hpp"

namespace arc {
	class Row {
	public:
		explicit Row(const std::string &row, const std::pair<float, float> &pos, int fontSize);

		Text *getLetter(int idx) const;
		size_t size() const;
	private:
		std::vector<std::unique_ptr<Text>> _letters;
		std::pair<float, float> _pos;
		int _fontSize;
	};
}

#endif
