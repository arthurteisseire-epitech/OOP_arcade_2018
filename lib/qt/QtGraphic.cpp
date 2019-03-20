/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** QtGraphic.cpp
*/

#include "QtGraphic.hpp"

arc::IGraphic *entryPoint()
{
	return new arc::QtGraphic();
}

arc::QtGraphic::QtGraphic()
{
	_av[0] = strdup("arcade");
	_app = std::make_unique<QApplication>(_ac, _av);
	_widget = std::make_unique<Widget>();

	QPalette palette;
	palette.setColor(QPalette::Background, Qt::black);
	_widget->setAutoFillBackground(true);
	_widget->setPalette(palette);
	_widget->show();
}

bool arc::QtGraphic::isOpen() const
{
	return _widget->isVisible();
}

void arc::QtGraphic::draw()
{
	_widget->repaint();
}

bool arc::QtGraphic::processSprite(const ISprite &sprite)
{
	return _widget->processSprite(sprite);
}

bool arc::QtGraphic::processText(const IText &text)
{
	return _widget->processText(text);
}

bool arc::QtGraphic::processAudio(const arc::IAudio &audio)
{
	return _widget->processAudio(audio);
}

void arc::QtGraphic::processEvents()
{
	_widget->updateKeysState();
	QApplication::processEvents();
}

const std::map<arc::Key, arc::KeyState> &arc::QtGraphic::getKeys() const
{
        return _widget->getKeys();
}
