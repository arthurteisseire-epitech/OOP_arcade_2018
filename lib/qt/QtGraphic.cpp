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
	_thread(&QtGraphic::init, this, &ac, av)
{
}

QtGraphic::~QtGraphic()
{
	_thread.join();
}

void QtGraphic::init(int *ac, char **av)
{
	_app = std::make_unique<QApplication>(*ac, av);
	_centralWidget = std::make_unique<QWidget>();
	_window = std::make_unique<QMainWindow>();
	_window->setCentralWidget(_centralWidget.get());
	_window->show();
	_app->exec();
}

#include <iostream>
void QtGraphic::processSprite(QColor color)
{
	std::cout << "hello" << std::endl;
}

void QtGraphic::draw()
{
}

bool QtGraphic::isOpen()
{
	return _window->isVisible();
}
