##
## EPITECH PROJECT, 2017
## caca
## File description:
## cacc for 2018
##

CC	=	g++

SRC 	=	CacaGraphic.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I. -I./../ -I../../component  -Wall -Wextra -W -fPIC -lcaca -lImlib2 -std=c++14
LDFLAGS		=	-shared

NAME	=	lib_arcade_caca.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
