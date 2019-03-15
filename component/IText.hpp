/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IText.hpp,
*/

#ifndef ARCADE_ITEXT_HPP
#define ARCADE_ITEXT_HPP

#include <string>
#include "IComponent.hpp"

namespace arc {
	class IText : public IComponent {
	public:
		~IText() override = default;

		virtual const std::string &getText() const = 0;
		virtual const std::pair<float, float> &getPosition() const = 0;
		virtual int getFontSize() const = 0;
		virtual const std::string &getFontPath() const = 0;
	};
}

#endif
