/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.hpp
*/

#ifndef ARCADE_ISPRITE_HPP
#define ARCADE_ISPRITE_HPP

#include <string>

class ISprite {
public:
	virtual const std::string &getPath() const = 0;
};

#endif
