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
#include "IText.hpp"
#include "Text.hpp"
#include "ISprite.hpp"
#include "Sprite.hpp"
#include "Key.hpp"
#include "Button.hpp"
#include "Audio.hpp"

namespace arc {
	class MainMenu {
	public:
		MainMenu();
		std::vector<std::reference_wrapper<ISprite>> getSprites() const;
		std::vector<std::reference_wrapper<IText>> getTexts() const;
		void processEvents(const std::map<Key, KeyState> &map);
	private:
		void moveFocusDown();
		void moveFocusUp();
		void setSpritesPosition();
		void setSpritesSize();

		size_t _focus;
		std::vector<std::unique_ptr<Button>> _buttons;
		std::unique_ptr<Sprite> _spriteFocus;
		std::unique_ptr<Audio> _audio;
		static std::map<Key, void (arc::MainMenu::*)()> _keysMap;
	};
}

#endif
