/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <QtWidgets/QApplication>
#include "SharedLibrary.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	SharedLibrary library;
	void (*show)();

	library.load("lib/qt/libqt5.so");
	show = (void (*)())library.sym("showWidget");
	show();
	return app.exec();
}
