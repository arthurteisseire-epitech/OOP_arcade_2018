/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderException.cpp
*/

#include "LibraryLoaderException.hpp"

LibraryLoaderException::LibraryLoaderException(const std::string &message) :
	_message("SharedLibraryError: " + message)
{
}

char const *LibraryLoaderException::what() const noexcept
{
	return _message.c_str();
}
