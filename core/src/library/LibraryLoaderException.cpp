/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** LibraryLoaderException.cpp
*/

#include "LibraryLoaderException.hpp"

arc::LibraryLoaderException::LibraryLoaderException(const std::string &message) :
	_message("SharedLibraryError: " + message)
{
}

char const *arc::LibraryLoaderException::what() const noexcept
{
	return _message.c_str();
}
