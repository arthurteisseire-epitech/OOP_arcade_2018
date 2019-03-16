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
		Scenes();
		void changeScene(IScene *scene);
	protected:
		std::unique_ptr<IScene> _scene;
	};
}

#endif
