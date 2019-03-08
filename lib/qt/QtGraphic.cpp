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

QtGraphic::QtGraphic(int &ac, char *av[])
{
	_thread = std::thread(&QtGraphic::init, this, &ac, av);
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
	_app->exec();
}

void QtGraphic::processSprite(QColor color)
{
	QPalette palette;
	palette.setColor(QPalette::Background, color);
	_centralWidget->setAutoFillBackground(true);
	_centralWidget->setPalette(palette);
}

void QtGraphic::draw()
{
	_window->show();
}

bool QtGraphic::isOpen()
{
	return _window->isActiveWindow();
}
