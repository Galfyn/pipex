# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galfyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 17:59:33 by galfyn            #+#    #+#              #
#    Updated: 2021/11/12 18:24:17 by galfyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
NAME_BONUS	=	pipex

SRCS =	ft_command_path.c	\
		get_next_line.c		\
		pipex_utils.c 		\
		ft_substr.c 		\
		ft_strchr.c 		\
		ft_split.c 			\
		ft_error.c			\

MAIN			=	pipex.c
MAIN_B 			= 	pipex_bonus.c

OBJ				= $(patsubst %.c,%.o,$(SRCS) $(MAIN))
OBJ_BONUS		= $(patsubst %.c,%.o,$(SRCS) $(MAIN_B))

INCL			=	pipex.h

CFLAGS			=	-Wall -Wextra -Werror

all				: $(NAME)

$(NAME)			: $(OBJ)
					gcc $(OBJ) -o $(NAME)
					@echo "\033[32m Pipex Compiled done! ☯ "

$(NAME_BONUS)	: $(OBJ_BONUS)
					gcc $(OBJ_BONUS) -o $(NAME_BONUS)
					@echo "\033[32m Pipex Compiled done! ☯ "

bonus			: $(NAME_BONUS)

%.o				: %.c $(INCL)
					gcc $(CFLAGS) -c $< -o $@

clean 			:
					@rm -f $(OBJ) $(OBJ_BONUS)
					@echo "\033[33m ----Clean completed----"

fclean			: clean
					@rm -f $(NAME)
					@echo "\033[33m ----Fclean completed----"

re				: fclean all

.PHONY			: all clean fclean re bonus
