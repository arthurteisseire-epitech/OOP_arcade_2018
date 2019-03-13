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
	_centralWidget(new Widget()),
	_window(new QMainWindow()),
	_button(new QPushButton("Quit", _centralWidget.get()))
{
	QObject::connect(_button.get(), &QAbstractButton::clicked, this, [this] {
		this->_window->setVisible(false);
	});
	_window->setCentralWidget(_centralWidget.get());
	_window->show();
}

void QtGraphic::processSprite(const ISprite &sprite)
{
	_app->setActiveWindow(_window.get());
	_centralWidget->processSprite(sprite);
	_centralWidget->repaint();
}

#include <iostream>
void QtGraphic::processText(const IText &text)
{
	std::cout << text.getText() << std::endl;
}

bool QtGraphic::isOpen()
{
	QApplication::processEvents();
	return _window->isVisible();
}

void QtGraphic::draw()
{
}
