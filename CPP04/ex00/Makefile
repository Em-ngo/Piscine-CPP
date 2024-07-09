_NC=`tput sgr0`
_RED=\033[0;31m
_GREEN=\033[0;32m
_YELLOW=\033[0;33m
_BLUE=\033[0;34m
_PURPLE=\033[0;95m
_CYAN=\033[0;36m
_WHITE=\033[0;37m

CXX = c++
CFLAGS =	-Wall -Werror -Wextra -g -std=c++98
SRCDIR =	./
OBJDIR =
DEPS =

SRC =	main.cpp  \
		Dog.cpp	\
		Cat.cpp	\
		Animal.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJ :=	$(patsubst %.cpp, $(OBJDIR)%.o, $(SRC))
SRC :=	$(addprefix $(SRCDIR), $(SRC))
DEPS :=	$(addprefix $(SRCDIR), $(DEPS))

NAME =	animal

all :	$(NAME) $(BONUS_NAME)

$(NAME):	$(OBJ)
		@$(CXX) $^ -o $@

%.o:	$(SRCDIR)%.cpp $(DEPS)
	@printf "$(_PURPLE)Generating obj... %-33.33s\r$(_NC)" $(notdir $@)
	@$(CXX) -c $(CFLAGS) $(DEPS) $^

clean :
	@printf "$(_RED)Supressing obj... %-33.33s\r$(_NC)" $(notdir $@)
	@rm -f *.o

fclean :	clean
	@printf "$(_RED)Supressing obj... %-33.33s\r$(_NC)" $(notdir $@)
	@rm -f $(NAME) $(BONUS_NAME)

re :	fclean all

.PHONY :	all clean fclean re bonus