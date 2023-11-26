SRC		=	$(addprefix src/,	main.cpp\
								Vector2.cpp\
								Graph.cpp)

OBJDIR	=	obj
SRCDIR	=	src
OBJ		=	$(addprefix  obj/, $(notdir  $(SRC:.cpp=.o)))
NAME	=	graph
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -MD -MP -std=c++98 -I include
DEPENDS :=	$(addprefix  obj/, $(notdir  $(SRC:.cpp=.d)))




.PHONY			:	all re clean fclean

all				:	$(NAME)

$(NAME)			:	$(OBJ) Makefile
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o	:	$(SRCDIR)/%.cpp
					$(CC) $(CFLAGS) -c -o $@ $<

clean			:	
					rm -f $(OBJ) $(DEPENDS)
					rm -r $(OBJDIR)

fclean			:	clean
					rm -f $(NAME)

x				:	all
					./$(NAME)

leaks			:	all
					leaks --atExit -- ./$(NAME)

$(OBJ)			: | $(OBJDIR)

$(OBJDIR)		: 
					mkdir $(OBJDIR)

re				:	fclean all

-include $(DEPENDS)