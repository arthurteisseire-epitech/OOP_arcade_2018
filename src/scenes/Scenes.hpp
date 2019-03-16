/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scenes.hpp
*/

#ifndef ARCADE_SCENES_HPP
#define ARCADE_SCENES_HPP

namespace arc {
	class Scenes {
	public:
		Scenes();
		void changeScene(int idx);
	protected:
		int _currScene;
	};
}

#endif
