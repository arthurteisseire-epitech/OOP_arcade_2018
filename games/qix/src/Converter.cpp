/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Converter.cpp
*/

#include "Converter.hpp"

std::pair<float, float> arc::Converter::PosToPourcent(arc::Player::Position pos, int width, int height)
{
	return {(float)pos.x / (float)width,
	        (float)pos.y / (float)height};
}
