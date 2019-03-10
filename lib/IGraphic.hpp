/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGraphic.hpp
*/

#ifndef OOP_ARCADE_2018_IGRAPHIC_HPP
#define OOP_ARCADE_2018_IGRAPHIC_HPP

#include "ASprite.hpp"

class IGraphic {
public:
	virtual void draw() = 0;
	virtual bool isOpen() = 0;
	virtual void processSprite(const ASprite &sprite) = 0;
};

#endif
