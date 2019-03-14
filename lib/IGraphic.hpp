/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IGraphic.hpp
*/

#ifndef ARCADE_IGRAPHIC_HPP
#define ARCADE_IGRAPHIC_HPP

#include <vector>
#include "Key.hpp"
#include "ISprite.hpp"
#include "IText.hpp"

namespace arc {
	class IGraphic {
	public:
		virtual void draw() = 0;
		virtual bool isOpen() const = 0;
		virtual bool processSprite(const ISprite &sprite) = 0;
		virtual bool processText(const IText &text) = 0;
		virtual void processEvents() = 0;
		virtual const std::vector<Key> &getKeys() const = 0;
	};
}

#endif
