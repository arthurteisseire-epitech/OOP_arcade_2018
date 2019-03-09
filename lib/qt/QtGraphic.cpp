/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** QtGraphic.cpp
*/

#include <QPixmap>
#include <iostream>
#include "QtGraphic.hpp"

IGraphic *entryPoint(int &ac, char *av[])
{
	return new QtGraphic(ac, av);
}

QtGraphic::QtGraphic(int &ac, char *av[]) :
	_app(new QApplication(ac, av)),
	_centralWidget(new QWidget()),
	_window(new QMainWindow()),
	_button(new QPushButton("Quit", _centralWidget.get()))
{
	QObject::connect(_button.get(), &QAbstractButton::clicked, this, [this] {
		this->_window->setVisible(false);
	});
	_window->setCentralWidget(_centralWidget.get());
	_window->show();
}

void QtGraphic::processSprite(QColor color)
{
	QPalette p;

	p.setColor(QPalette::Background, color);
	_centralWidget->setAutoFillBackground(true);
	_centralWidget->setPalette(p);
}

bool QtGraphic::isOpen()
{
	QApplication::processEvents();
	return _window->isVisible();
}

void QtGraphic::draw()
{
}
