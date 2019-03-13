/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <unistd.h>
#include <iostream>
#include "Process.hpp"
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"
#include "MainMenu.hpp"
#include "IGame.hpp"

int main(int argc, char *argv[])
{
	arc::MainMenu mainMenu;
	arc::LibraryLoader graphicLoader(argc, argv);
	arc::LibraryLoader gameLoader(argc, argv);
	IGraphic *graphic = nullptr;
	IGame *game = nullptr;

	try {
		graphic = graphicLoader.loadInstance<IGraphic>("lib/qt/lib_arcade_qt5.so");
		game = gameLoader.loadInstance<IGame>("games/nibbler/lib_arcade_nibbler.so");
	} catch (arc::LibraryLoaderException &exception) {
		std::cerr << exception.what() << std::endl;
		return (84);
	}
	while (graphic->isOpen()) {
		arc::Process::all(game->getComponents(), graphic);
		usleep(100);
	}
	return 0;
}