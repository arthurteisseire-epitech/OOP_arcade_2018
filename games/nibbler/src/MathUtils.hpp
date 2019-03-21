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

pos_t operator+(const pos_t &p1, const pos_t &p2);

pos_t operator-(const pos_t &p1, const pos_t &p2);

std::pair<float, float> operator/(const pos_t &p1, const unsigned int &div);

#endif
