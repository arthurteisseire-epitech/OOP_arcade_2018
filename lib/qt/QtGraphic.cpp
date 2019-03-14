/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** QtGraphic.cpp
*/

#include "QtGraphic.hpp"

IGraphic *entryPoint(int &ac, char *av[])
{
	return new arc::QtGraphic(ac, av);
}

arc::QtGraphic::QtGraphic(int &ac, char *av[]) :
	_app(new QApplication(ac, av)),
	_widget(new Widget())
{
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

void arc::QtGraphic::processEvents()
{
	QApplication::processEvents();
}

const std::vector<Key> &arc::QtGraphic::getKeys() const
{
        return _widget->getKeys();
}
