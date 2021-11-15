# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galfyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 17:59:33 by galfyn            #+#    #+#              #
#    Updated: 2021/11/15 16:50:46 by galfyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	mandatory/pipex
NAME_B			=	bonus/pipex

SRCS			=	global/ft_command_path.c	\
					global/get_next_line.c		\
					global/pipex_utils.c 		\
					global/ft_substr.c 			\
					global/ft_strchr.c 			\
					global/ft_split.c 			\
					global/ft_error.c			\

MAIN			=	mandatory/pipex.c
MAIN_B 			= 	bonus/pipex_bonus.c

OBJ				= 	$(patsubst %.c,%.o,$(SRCS) $(MAIN))
OBJ_B			= 	$(patsubst %.c,%.o,$(SRCS) $(MAIN_B))

INCL			=	-I./pipex.h

CFLAGS			=	-Wall -Wextra -Werror

all				: 	$(NAME)

$(NAME)			: 	$(OBJ)
						gcc $(CFLAGS) $(OBJ) -o $(NAME)
						@echo "\033[32m Pipex Compiled done! ☯ "
$(NAME_B)		: 	$(OBJ_B)
						gcc $(CFLAGS) $(OBJ_B) -o $(NAME_B)
						@echo "\033[32m Pipex_bonus Compiled done! ☯ "

bonus			: 	$(NAME_B)

clean 			:
						@rm -f $(OBJ) $(OBJ_B)
						@echo "\033[33m ----Clean completed----"

fclean			: 	clean
						@rm -f $(NAME) $(NAME_B)
						@echo "\033[33m ----Fclean completed----"

re				: 	fclean all

.PHONY			:	all clean fclean re bonus
