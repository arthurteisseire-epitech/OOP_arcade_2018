/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IAudio.hpp
*/

#ifndef OOP_ARCADE_2018_I_AUDIO_HPP
#define OOP_ARCADE_2018_I_AUDIO_HPP

#include <string>
#include "IComponent.hpp"

namespace arc {

	class IAudio : public IComponent {
	public:

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
