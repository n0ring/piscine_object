SRC		=	main.cpp \
			Bank.cpp\
			Account.cpp
T_SRC = Account.cpp\
			Bank.cpp
OBJ		=	$(SRC:.c=.o)
NAME	=	Bank
T_NAME	=	Test
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror 

.PHONY			:	all re clean fclean

all				:	$(NAME)

$(NAME)			:	$(OBJ) Makefile
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o	: %.cpp
					$(CC) $(CFLAGS) -c -o $@ $<

clean			:	
					rm -f $(OBJ)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

x				: $(NAME)
					./$(NAME)

test			:
					$(CC) $(CFLAGS) tests/test_main.cpp $(T_SRC) -o $(T_NAME)
					./$(T_NAME)
