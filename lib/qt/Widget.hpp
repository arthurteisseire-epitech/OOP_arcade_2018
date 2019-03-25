/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.hpp
*/

#ifndef ARCADE_WIDGET_HPP
#define ARCADE_WIDGET_HPP

#include <memory>
#include <QWidget>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <unordered_map>
#include "IText.hpp"
#include "IAudio.hpp"
#include "ISprite.hpp"
#include "Key.hpp"

namespace arc {
	class Widget : public QWidget {
	public:
		Widget() = default;
		bool processSprite(const ISprite &sprite);
		bool processText(const IText &text);
		bool processAudio(const IAudio &audio);
		const std::map<Key, KeyState> &getKeys() const;
		void updateKeysState();
	protected:
		void paintEvent(QPaintEvent *e) override;
		void keyPressEvent(QKeyEvent *e) override;
		void keyReleaseEvent(QKeyEvent *e) override;
	private:
		void processKeys(const QKeyEvent *e, arc::KeyState state);
		QColor convertColor(unsigned int color);

		std::map<const ISprite *, std::unique_ptr<QPixmap>> _sprites;
		std::vector<std::pair<const ISprite *, std::unique_ptr<QPixmap>>> _spritesToDraw;
		std::vector<const IText *> _texts;
		std::vector<const IText *> _textsToDraw;
		std::map<const IAudio *, std::unique_ptr<QMediaPlayer>>_player;
		std::map<Key, KeyState> _keys;
		static std::map<Qt::Key, Key> _qKeys;
	};
}

#endif
