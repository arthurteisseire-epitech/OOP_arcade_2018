/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IAudio.hpp
*/

#ifndef ARCADE_IAUDIO_HPP
#define ARCADE_IAUDIO_HPP

#include <string>
#include "IComponent.hpp"

namespace arc {
	class IAudio : public IComponent {
	public:

		~IAudio() override = default;

		/**
		 * @return the audio volume between 0 and 100
		 */
		virtual int getVolume() const = 0;

		/**
		 * @return the relative audio file path to be loaded
		 */
		virtual const std::string &getSoundPath() const = 0;
	};
}

#endif
