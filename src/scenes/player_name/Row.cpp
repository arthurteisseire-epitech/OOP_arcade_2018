/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Row.cpp
*/

#include <memory>
#include "Row.hpp"

arc::Row::Row(const std::string &row, const std::pair<float, float> &pos, int fontSize) :
	_pos(pos),
	_fontSize(fontSize)
{
	for (size_t i = 0; i < 8; ++i) {
		_letters.push_back(std::make_unique<Text>(std::string(1, row[i]),
		                                          std::pair<float, float>(i / 10.0, 0.3),
		                                          20));
	}
}

arc::Text *arc::Row::getLetter(size_t idx) const
{
	return _letters[idx].get();
}

size_t arc::Row::size() const
{
	return _letters.size();
}
