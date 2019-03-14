/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ArgParser.cpp
*/

#include <iostream>
#include "ArgParser.hpp"

arc::ArgParser::ArgParser(int &argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage : " << std::endl
		          << "\t" << std::string(argv[0]) + " ./lib[graphical_libname].so" << std::endl
		          << std::endl;
		exit(84);
	}
}

arc::Core arc::ArgParser::createCore()
{
	return arc::Core(nullptr);
}
