/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.cpp
*/

#include "Graphic.hpp"

IGraphic *entryPoint(int &ac, char *av[])
{
	return new Graphic(ac, av);
}

Graphic::Graphic(int &ac, char *av[]) :
	_centralWidget(std::make_unique<QWidget>()),
	_window(std::make_unique<QMainWindow>()),
	_thread(&Graphic::startEventLoop, this, ac, av)
{
	_window->setCentralWidget(_centralWidget.get());
}

Graphic::~Graphic()
{
	_thread.join();
}

void Graphic::startEventLoop(int &ac, char **av)
{
	_app = std::make_unique<QApplication>(ac, av);
	_app->exec();
}

void Graphic::processSprite(QColor color)
{
	QPalette palette;
	palette.setColor(QPalette::Background, color);
	_centralWidget->setAutoFillBackground(true);
	_centralWidget->setPalette(palette);
}

void Graphic::draw()
{
	_window->show();
}

bool Graphic::isOpen()
{
        return _window->isActiveWindow();
}
