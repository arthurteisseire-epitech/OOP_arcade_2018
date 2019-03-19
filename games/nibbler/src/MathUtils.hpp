/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MathUtils.hpp
*/

#ifndef ARCADE_MATHUTILS_HPP
#define ARCADE_MATHUTILS_HPP

#include "Pos.hpp"


std::pair<float, float> operator/(const pos_t &p1, const pos_t &div);

std::pair<unsigned int, unsigned int> operator+(const std::pair<unsigned int, unsigned int> &p1, const std::pair<unsigned int, unsigned int> &p2);

std::pair<unsigned int, unsigned int> operator-(const std::pair<unsigned int, unsigned int> &p1, const std::pair<unsigned int, unsigned int> &p2);

std::pair<float, float> operator/(const pos_t &p1, const unsigned int &div);


#endif //ARCADE_MATHUTILS_HPP
