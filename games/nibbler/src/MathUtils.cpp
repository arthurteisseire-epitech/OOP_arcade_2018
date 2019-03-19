/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MathUtils.cpp
*/

#include "MathUtils.hpp"

std::pair<float, float> operator/(const std::pair<unsigned int, unsigned int> &p1, const unsigned int &div)
{
	return {(float)p1.first / div, (float)p1.second / div};
}

std::pair<float, float> operator/(const pos_t &p1, const pos_t &div)
{
	return {(float)p1.first / div.first, (float)p1.second / div.second};
}

std::pair<unsigned int, unsigned int> operator+(const std::pair<unsigned int, unsigned int> &p1, const std::pair<unsigned int, unsigned int> &p2)
{
	return {p1.first + p2.first, p1.second + p2.second};
}

std::pair<unsigned int, unsigned int> operator-(const std::pair<unsigned int, unsigned int> &p1, const std::pair<unsigned int, unsigned int> &p2)
{
	return {p1.first - p2.first, p1.second - p2.second};
}
