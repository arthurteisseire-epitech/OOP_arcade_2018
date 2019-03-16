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
		enum SCENE {
			MENU, PLAYER_NAME
		};

		Scenes();
		void changeScene(SCENE scene);
	protected:
		SCENE _currScene;
	};
}

#endif
