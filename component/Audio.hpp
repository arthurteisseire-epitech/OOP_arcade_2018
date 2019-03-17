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
		explicit Audio(const std::string &path, int volume = 10);
		~Audio() override = default;

		ComponentType getType() const override;
		int getVolume() const override;
		const std::string &getSoundPath() const override;
		void setVolume(int volume);
		void setPath(const std::string &path);
	private:
		std::string _path;
		int _volume;
	};
}

#endif
