# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 15:28:36 by guilmira          #+#    #+#              #
#    Updated: 2021/09/27 14:32:18 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME	= server
NAME2	= client
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

#--------------------------------------------------------------------------------------------------------------LIBS
PF_DIR		= ./ft_printf
PF			= $(PF_DIR)/libftprintf.a
LIB_DIR		= $(PF_DIR)/libft_submodule
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./ft_printf/0includes -I ./ft_printf/libft_submodule/0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		= 0server.c
SRCS2		= 1client.c
OBJS		= $(SRCS:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
OBJS_DIR	= ./0objects
#--------------------------------------------------------------------------------------------------------------RULES
all: ft_printf $(NAME) $(NAME2)

$(PF):
	@make -C $(PF_DIR)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(GNL) $(PF)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(PF) $(LIB) -o $(NAME)
	@mv $(OBJS) ./0objects
	@echo "'$(NAME)' is now compiled."

$(NAME2): $(OBJS2) $(GNL) $(PF) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS2) $(INCLUDES) $(PF) $(LIB) -o $(NAME2)
	@mv $(OBJS2) ./0objects
	@echo "'$(NAME2)' is now compiled."

ex: $(NAME) $(NAME2)
	./$(NAME)

bonus: all

clean:
	@rm -rf $(OBJS_DIR)/$(OBJS)
	@rm -rf $(OBJS_DIR)/$(OBJS2)
	make clean -C $(PF_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME2)
	@make fclean -C $(PF_DIR)

re: fclean all

.PHONY: all clean fclean re
