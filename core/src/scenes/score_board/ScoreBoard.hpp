/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScoreBoard.hpp
*/

#ifndef ARCADE_SCOREBOARD_HPP
#define ARCADE_SCOREBOARD_HPP

#include "Text.hpp"
#include "Scene.hpp"

namespace arc {
	class ScoreBoard : public Scene {
	public:
		explicit ScoreBoard(const std::shared_ptr<SharedData> &playerData);
		void update(const std::map<Key, KeyState> &keys, float deltaTime) override;
		std::vector<std::reference_wrapper<const IComponent>> getComponents() const override;
		arc::SCENE nextScene(const std::map<Key, KeyState> &keys) const override;
	private:
		void createTexts();

		Text _header;
		std::vector<std::pair<int, std::pair<std::string, std::string>>> _rows;
		std::vector<Text> _gameNames;
		std::vector<Text> _playerNames;
		std::vector<Text> _scores;
	};
}

#endif
