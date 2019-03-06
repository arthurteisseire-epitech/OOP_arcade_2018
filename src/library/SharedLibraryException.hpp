/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibraryException.hpp
*/

#ifndef OOP_ARCADE_2018_SHAREDLIBRARYEXCEPTION_HPP
#define OOP_ARCADE_2018_SHAREDLIBRARYEXCEPTION_HPP

#include <exception>

class SharedLibraryException : public std::exception {
public:
	SharedLibraryException() = default;
	~SharedLibraryException() override = default;
	char const *what() const noexcept override;
};

#endif
