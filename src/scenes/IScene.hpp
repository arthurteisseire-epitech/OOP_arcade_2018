/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IScene.hpp
*/

#ifndef ARCADE_ISCENE_HPP
#define ARCADE_ISCENE_HPP

#include <functional>
#include <vector>
#include <map>
#include "ISprite.hpp"
#include "IText.hpp"
#include "IAudio.hpp"
#include "Key.hpp"
#include "Scenes.hpp"

namespace arc {
	class IScene {
	public:
		virtual ~IScene() = default;
		virtual std::vector<std::reference_wrapper<ISprite>> getSprites() const = 0;
		virtual std::vector<std::reference_wrapper<IText>> getTexts() const = 0;
		virtual std::vector<std::reference_wrapper<IAudio>> getAudios() const = 0;
		virtual void processEvents(const std::map<Key, KeyState> &map) = 0;
		virtual SCENE nextScene() const = 0;
	};
}

#endif
