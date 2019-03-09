/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <QtGui/QColor>
#include <thread>
#include <unistd.h>
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"

int main(int argc, char *argv[])
{
	LibraryLoader loader(argc, argv);
	IGraphic *g = loader.loadGraphicInstance("lib/qt/lib_arcade_qt5.so");
	int i = 0;

        while (g->isOpen()) {
        	usleep(1);
		if (i % 2 == 0)
			g->processSprite(Qt::black);
		else
			g->processSprite(Qt::white);
		i++;
	}
	return 0;
}
