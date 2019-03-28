/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Converter.cpp
*/

#include "Converter.hpp"

std::pair<float, float> arc::Converter::PosToPercent(const Position &pos, const Position &dimension)
{
	return {(float)pos.x / (float)dimension.x,
	        (float)pos.y / (float)dimension.y};
}

std::pair<float, float> arc::Converter::SizeToPercent(const Position &dimension)
{
	return {1.0f / dimension.x, 1.0f / dimension.y};
}
