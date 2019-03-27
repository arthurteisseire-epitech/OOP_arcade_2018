##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile
##

CC		=	g++

DSRC	=	src/
DCOMPONENT	=	../../component/
INC		=	-I$(DSRC) -I$(DCOMPONENT) -I..

SRC		=	$(DSRC)Game.cpp			\
			$(DSRC)Player.cpp		\
			$(DSRC)Map.cpp			\
			$(DSRC)Cell.cpp			\
			$(DSRC)Converter.cpp		\
			$(DCOMPONENT)Sprite.cpp		\

CXXFLAGS	+=  -Wall -Wextra $(INC) -shared -fPIC
OBJ		=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_qix.so

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
