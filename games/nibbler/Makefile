##
## EPITECH PROJECT, 2018
## arcade
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
			$(DSRC)Food.cpp			\
			$(DCOMPONENT)Sprite.cpp	\
			$(DCOMPONENT)Text.cpp	\
			$(DSRC)MathUtils.cpp	\

INC		=	-I$(DSRC) -I$(DCOMPONENT) -I$(DGAMES)

CXXFLAGS	+=	-Wall -Wextra $(INC) -fPIC -std=c++14
LDFLAGS		+=	-shared
OBJ		=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_nibbler.so

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)
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
