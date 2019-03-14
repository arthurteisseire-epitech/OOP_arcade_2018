/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <unistd.h>
#include <iostream>
#include "ArgParser.hpp"
#include "Core.hpp"
#include "Text.hpp"
#include "Process.hpp"
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"
#include "MainMenu.hpp"
#include "IGame.hpp"

int main(int argc, char *argv[])
{
	arc::ArgParser argParser(argc, argv);

	auto core = argParser.createCore();
	arc::MainMenu mainMenu;
	arc::LibraryLoader graphicLoader(argc, argv);
	arc::LibraryLoader gameLoader(argc, argv);
	Text text("hello", 60, std::pair<float, float>(0.1, 0.1));
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
		arc::Process::sprites(mainMenu.getSprites(), graphic);
		graphic->processText(text);
		graphic->processEvents();
		mainMenu.processEvents(graphic->getKeys());
		usleep(100);
	}
	return 0;
}