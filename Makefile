NAME = pipex

SRC = pipex.c ft_command.c pipex_utils.c ft_split.c ft_substr.c

OBJ = $(patsubst %.c,%.o,$(SRC))

INCL = pipex.h

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc $(OBJ) -o $@
	@echo "\033[32mPipex Compiled! ☯ "

%.o : %.c $(INCL)
	@gcc $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@echo "\033[33m----Clean completed----"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[33m----Fclean completed----"

re : fclean all

.PHONY : all clean fclean re
