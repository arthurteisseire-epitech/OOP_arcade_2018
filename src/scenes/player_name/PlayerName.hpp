/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.hpp
*/

#ifndef ARCADE_PLAYERNAME_HPP
#define ARCADE_PLAYERNAME_HPP

#include <memory>
#include "IScene.hpp"
#include "Text.hpp"
#include "Cursor.hpp"
#include "Row.hpp"

namespace arc {
	class PlayerName : public IScene {
	public:
		PlayerName();
		std::vector<std::reference_wrapper<ISprite>> getSprites() const override;
		std::vector<std::reference_wrapper<IText>> getTexts() const override;
		std::vector<std::reference_wrapper<IAudio>> getAudios() const override;
		void processEvents(const std::map<Key, KeyState> &keys) override;
		void action(SceneManager &sceneManager) override;
	private:
		void moveFocusLeft();
		void moveFocusRight();
		void moveFocusUp();
		void moveFocusDown();
		bool in(int x, int y) const;
		Text *getFocus() const;

		std::unique_ptr<Text> _playerName;
		std::vector<Row> _gridLetters;
		std::unique_ptr<Cursor> _cursor;
		std::pair<int, int> _focus;
		static std::map<Key, void (arc::PlayerName::*)()> _keysMap;
	};
}

#endif
