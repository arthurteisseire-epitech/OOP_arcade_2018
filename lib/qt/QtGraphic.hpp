/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** QtGraphic.hpp
*/

#ifndef ARCADE_QTGRAPHIC_HPP
#define ARCADE_QTGRAPHIC_HPP

#if defined ARCADE
#define COMMON_SO Q_DECL_EXPORT
#else
#define COMMON_SO Q_DECL_IMPORT
#endif

#include <QtGui>
#include <QtWidgets>
#include <QMediaPlayer>
#include "IGraphic.hpp"
#include "ISprite.hpp"
#include "Widget.hpp"
#include "Key.hpp"

namespace arc {
	class QtGraphic : public IGraphic, public QObject {
	public:
		QtGraphic(int &ac, char *av[]);
		bool isOpen() const override;
		void draw() override;
		bool processSprite(const ISprite &sprite) override;
		bool processText(const IText &text) override;
		bool processAudio(const IAudio &audio) override;
		void processEvents() override;
		const std::map<Key, KeyState> &getKeys() const override;
	private:
		std::unique_ptr<QApplication> _app;
		std::unique_ptr<Widget> _widget;
		std::unique_ptr<QMediaPlayer> _player;
	};
}

extern "C" COMMON_SO arc::IGraphic *entryPoint(int &ac, char *av[]);

#endif
