/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ASprite.hpp
*/

#ifndef ARCADE_ASPRITE_HPP
#define ARCADE_ASPRITE_HPP

#include <string>

class ASprite {
public:
	explicit ASprite(const std::string &filename);
	const std::string &getFilename();
private:
	std::string _filename;
};

#endif
