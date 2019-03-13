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
	_centralWidget(new Widget())
{
	_centralWidget->show();
}

void arc::QtGraphic::processSprite(const ISprite &sprite)
{
	_centralWidget->processSprite(sprite);
	_centralWidget->repaint();
}

bool arc::QtGraphic::isOpen()
{
	QApplication::processEvents();
	return _centralWidget->isVisible();
}

void arc::QtGraphic::draw()
{
}

const std::vector<Key> &arc::QtGraphic::getKeys() const
{
        return _centralWidget->getKeys();
}
