/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Audio.hpp
*/

#ifndef ARCADE_AUDIO_HPP
#define ARCADE_AUDIO_HPP

#include "IAudio.hpp"

namespace arc {
	class Audio : public IAudio {
	public:
		int getVolume() const override;
		const std::string &getSoundPath() const override;
		void setVolume(int volume);
		void setPath(const std::string &path);
	private:
		int _volume;
		std::string _path;
	};
}

#endif
