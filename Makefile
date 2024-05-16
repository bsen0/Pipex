# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 15:27:45 by bsen              #+#    #+#              #
#    Updated: 2024/03/15 12:45:44 by bsen             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	childs.c \
		pipex.c \
		
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f
NAME = pipex
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make all -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)


fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(OBJ)
	make clean -C libft

re : fclean all

.PHONY: re fclean clean all