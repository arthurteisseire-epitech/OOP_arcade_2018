##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

all:
	cmake . && make

clean:
	cmake . && make clean

fclean:
	cmake . && make fclean

re:
	cmake . && make re

tests_run:
	cmake . && make tests_run

.PHONY: all clean fclean re tests_run
