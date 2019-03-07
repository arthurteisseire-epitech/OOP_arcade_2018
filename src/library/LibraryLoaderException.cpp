/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderException.cpp
*/

#include "LibraryLoaderException.hpp"

SharedLibraryException::SharedLibraryException(const std::string &message) :
	_message("SharedLibraryError: " + message)
{
}

char const *SharedLibraryException::what() const noexcept
{
	return _message.c_str();
}
