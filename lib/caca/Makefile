##
## EPITECH PROJECT, 2017
## caca
## File description:
## cacc for 2018
##



SRC 	=	CacaGraphic.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I. -I./../ -I../../component  -Wall -Wextra -W -fPIC -lcaca -lImlib2

NAME	=	lib_arcade_caca.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(CXXFLAGS)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
