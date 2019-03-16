/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Scenes.hpp
*/

#ifndef ARCADE_SCENES_HPP
#define ARCADE_SCENES_HPP

#include <map>
#include <memory>
#include "IScene.hpp"

namespace arc {
	class Scenes {
	public:
		enum SCENE {
			MENU, PLAYER_NAME
		};

		Scenes();
		void changeScene(SCENE scene);
	protected:
		std::map<SCENE, std::unique_ptr<IScene>> _scenes;
		SCENE _currScene;
	};
}

#endif
