##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

CC	=	g++
DSRC	=	src/
INC	=	-I$(DSRC) -I.. -I../../component

SRC	=	$(DSRC)SfmlGraphic.cpp			\

CXXFLAGS=	-Wall -Wextra $(INC) -shared -fPIC -std=c++14
LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system
OBJ	=	$(SRC:.cpp=.o)
NAME	=	lib_arcade_sfml.so

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all


.PHONY: all clean fclean re
