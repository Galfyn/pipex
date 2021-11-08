NAME = pipex

SRC = main.c ft_command.c pipex_utils.c ft_split.c

OBJ = $(patsubst %.c,%.o,$(SRC))

INCL = pipex.h

#CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@#echo "\033[33m----Compiling lib----"
	@gcc $(OBJ) -LLibft -lft -o $@
	@echo "\033[32mPipex Compiled! ☯ "

%.o : %.c $(INCL)
	@gcc $(CFLAGS) -I./Libft -c $< -o $@

#libft :
#	@make -C Libft

clean :
	@rm -f $(OBJ)
	@#make clean -C Libft
	@echo "\033[33m----Clean completed----"

fclean : clean
	@rm -f $(NAME)
	@#rm -f Libft/libft.a
	@echo "\033[33m----Fclean completed----"

re : fclean all

.PHONY : all libft clean fclean re
