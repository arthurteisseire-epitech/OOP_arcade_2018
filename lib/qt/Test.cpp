/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.cpp
*/

#include <QtGui>
#include "Test.hpp"

QWidget *createWidget()
{
	auto widget = new QWidget();
	widget->resize(100, 100);
	return widget;
}
