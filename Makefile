# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 15:28:36 by guilmira          #+#    #+#              #
#    Updated: 2021/09/22 14:44:01 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME	= server
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#-g3 -fsanitize=address

#--------------------------------------------------------------------------------------------------------------LIBS
GNL			= ./get_next_line/gnl.a
PF			= ./ft_printf/libftprintf.a
GNL_DIR		= ./get_next_line
PF_DIR		= ./ft_printf

INCLUDES	= -I ./0includes -I ./get_next_line/0includes -I ./ft_printf/0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS = main.c 0server.c
OBJS = $(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: gnl ft_printf $(NAME)

gnl:
	@make -C $(GNL_DIR)

ft_printf:
	@make -C $(PF_DIR)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(GNL) $(PF)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES) $(GNL) $(PF) -o $(NAME)

ex: $(NAME)
	./$(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(GNL_DIR)
fclean: clean
	rm -rf $(NAME)
	make fclean -C $(GNL_DIR)
re: fclean all

.PHONY: all clean fclean re
