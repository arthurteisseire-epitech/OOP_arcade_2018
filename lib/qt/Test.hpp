/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.hpp
*/

#include <QtGui>
#include <QtWidgets>

#if defined ARCADE
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

extern "C" TEST_COMMON_DLLSPEC void showWidget();
