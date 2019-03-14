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

void arc::QtGraphic::processSprite(const ISprite &sprite)
{
	_widget->processSprite(sprite);
	_widget->repaint();
}

bool arc::QtGraphic::isOpen() const
{
	return _widget->isVisible();
}

void arc::QtGraphic::draw()
{
}

const std::vector<Key> &arc::QtGraphic::getKeys() const
{
        return _widget->getKeys();
}

void arc::QtGraphic::processEvents()
{
	QApplication::processEvents();
}

void arc::QtGraphic::processText(const IText &text)
{
	_widget->processText(text);
	_widget->repaint();
}
