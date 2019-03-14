/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGraphic.hpp
*/

#ifndef OOP_ARCADE_2018_IGRAPHIC_HPP
#define OOP_ARCADE_2018_IGRAPHIC_HPP

#include <vector>
#include "Key.hpp"
#include "ISprite.hpp"
#include "IText.hpp"

class IGraphic {
public:
	virtual void draw() = 0;
	virtual bool isOpen() const = 0;
	virtual void processSprite(const ISprite &sprite) = 0;
	virtual void processText(const IText &text) = 0;
	virtual void processEvents() = 0;
	virtual const std::vector<Key> &getKeys() const = 0;
};

#endif
