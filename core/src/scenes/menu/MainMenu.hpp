/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.hpp
*/

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include <vector>
#include <memory>
#include <map>
#include "Scene.hpp"
#include "IText.hpp"
#include "Text.hpp"
#include "ISprite.hpp"
#include "Sprite.hpp"
#include "Key.hpp"
#include "Button.hpp"
#include "Audio.hpp"

namespace arc {
	class MainMenu : public Scene {
	public:
		explicit MainMenu(const std::shared_ptr<SharedData> &playerData);
		void update(const std::map<Key, KeyState> &keys, float deltaTime) override;
		std::vector<std::reference_wrapper<const IComponent>> getComponents() const override;
		arc::SCENE nextScene(const std::map<Key, KeyState> &keys) const override;
	private:
		void moveFocusDown();
		void moveFocusUp();
		void setSpritesPosition();
		void setSpritesSize();

		std::vector<Text> _texts;
		std::vector<Button> _buttons;
		std::vector<Audio> _audios;
		Text _playerName;
		Sprite _spriteFocus;
		size_t _focus;
		static std::map<Key, void (arc::MainMenu::*)()> _keysMap;
	};
}

#endif
