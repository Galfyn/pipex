NAME		=	pipex
NAME_BONUS	=	pipex_b

SRCS = ft_command.c pipex_utils.c ft_split.c ft_substr.c get_next_line.c ft_strchr.c

MAIN = pipex.c
MAIN_B = pipex_bonus.c

OBJ			= $(patsubst %.c,%.o,$(SRCS) $(MAIN))
OBJ_BONUS	= $(patsubst %.c,%.o,$(SRCS) $(MAIN_B))

INCL		=	pipex.h

CFLAGS		=	-Wall -Wextra -Werror

all				: $(NAME)

$(NAME)			: $(OBJ)
					@gcc $(OBJ) -o $(NAME)
					@echo "\033[32mPipex Compiled! ☯ "

$(NAME_BONUS)	: $(OBJ_BONUS)
					@gcc $(OBJ_BONUS) -o $(NAME)
					@echo "\033[32mPipex Compiled! ☯ "

bonus			: $(NAME_BONUS) clean

#%.o				: %.c $(INCL)
#					@gcc $(CFLAGS) -c $< -o $@

clean 			:
					@rm -f $(OBJ) $(OBJ_BONUS)
					@echo "\033[33m----Clean completed----"

fclean			: clean
					@rm -f $(NAME)
					@echo "\033[33m----Fclean completed----"

re				: fclean all

.PHONY : all clean fclean re bonus
