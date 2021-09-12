# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 15:28:36 by guilmira          #+#    #+#              #
#    Updated: 2021/09/12 16:06:29 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME = server
CC = gcc
FLAGS = -Wall -Wextra -Werror
#-g3 -fsanitize=address
#INCLUDES	= -I ./libft_submodule/0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS = main.c 0server.c 3ft_tools.c
OBJS = $(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

ex: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) && ./$(NAME)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
