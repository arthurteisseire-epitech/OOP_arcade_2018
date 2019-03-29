/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.hpp
*/

#ifndef ARCADE_ISPRITE_HPP
#define ARCADE_ISPRITE_HPP

#include "IComponent.hpp"

namespace arc {
	class ISprite : public IComponent {
	public:
		~ISprite() override = default;

		/**
		 * @return the X and Y positions of the sprite between 0.0f and 1.0f
		 * relative to the entire window
		 * It's origin should be the upper left corner
		 */
		virtual const std::pair<float, float> &getPosition() const = 0;

		/**
		 * @return the relative texture path
		 */
		virtual const std::string &getTextureName() const = 0;

		/**
		 * @return the X and Y size of the sprite between 0.0f and 1.0f
		 * relative to the entire window
		 */
		virtual const std::pair<float, float> &getSize() const = 0;

		/**
		 * @return the fallback color when the texture cannot be loaded
		 */
		virtual unsigned int getColor() const = 0;
	};
}

#endif
