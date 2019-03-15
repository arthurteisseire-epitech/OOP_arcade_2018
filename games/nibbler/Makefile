##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile
##

CC		=	g++

DSRC	=	./src/
DCOMPONENT	=	../../component/
DGAMES	=	../

SRC		=	$(DSRC)Nibbler.cpp		\
			$(DSRC)Map.cpp			\
			$(DSRC)Snake.cpp		\
			$(DSRC)Food.cpp		\
			$(DCOMPONENT)Sprite.cpp	\
			$(DCOMPONENT)Text.cpp	\

INC		=	-I$(DSRC) -I$(DCOMPONENT) -I$(DGAMES)

CXXFLAGS	+=  -Wall -Wextra $(INC) -fPIC
OBJ		=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_nibbler.so

all: $(OBJ)
	$(CC) -o $(NAME) -shared $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
