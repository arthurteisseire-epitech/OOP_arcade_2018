/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** QtGraphic.cpp
*/

#include "QtGraphic.hpp"

IGraphic *entryPoint(int &ac, char *av[])
{
	return new QtGraphic(ac, av);
}

QtGraphic::QtGraphic(int &ac, char *av[]) :
	_app(new QApplication(ac, av)),
	_centralWidget(new Widget())
{
	_centralWidget->show();
}

void QtGraphic::processSprite(const ISprite &sprite)
{
	_centralWidget->processSprite(sprite);
	_centralWidget->repaint();
}

bool QtGraphic::isOpen()
{
	QApplication::processEvents();
	return _centralWidget->isVisible();
}

void QtGraphic::draw()
{
}

const std::vector<Key> &QtGraphic::getKeys() const
{
        return _centralWidget->getKeys();
}
