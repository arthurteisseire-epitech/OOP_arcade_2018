/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Test.hpp
*/

#include <QtGui>
#include <QtWidgets>
#include "IGraphic.hpp"

#if defined ARCADE
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

class App : public IGraphic {
public:
	App(int &ac, char *av[]);
	int exec() override;
	void createWidget() override;
	void showWidget() override;
private:
	QApplication *_app;
	QWidget *_widget;
};

extern "C" TEST_COMMON_DLLSPEC IGraphic *instantiate(int &ac, char *av[]);
