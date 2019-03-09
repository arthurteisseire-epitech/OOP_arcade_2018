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
	_app = std::make_unique<QApplication>(ac, av);
	_centralWidget = std::make_unique<QWidget>();
	_window = std::make_unique<QMainWindow>();
	_window->setCentralWidget(_centralWidget.get());
	_window->show();
}

QtGraphic::~QtGraphic()
{
	_app->quit();
}

void QtGraphic::processSprite(QColor color)
{
	QPalette p;

	p.setColor(QPalette::Background, color);
	_centralWidget->setAutoFillBackground(true);
	_centralWidget->setPalette(p);
}

void QtGraphic::draw()
{
}

bool QtGraphic::isOpen()
{
	QApplication::processEvents();
	return _window->isVisible();
}
