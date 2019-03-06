/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibraryException.cpp
*/

#include "SharedLibraryException.hpp"

SharedLibraryException::SharedLibraryException(const std::string &message) :
	_message(message)
{
}

char const *SharedLibraryException::what() const noexcept
{
	return std::string("SharedLibraryError: " + _message).c_str();
}
