# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 15:28:36 by guilmira          #+#    #+#              #
#    Updated: 2022/04/10 11:28:20 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= server
NAME2		= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR		= libft_submodule
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		= 0server.c
SRCS2		= 1client.c
OBJS		= $(SRCS:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: $(LIB) $(NAME) $(NAME2)

$(LIB):
	@make -C $(LIB_DIR)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) -o $(NAME)
	@echo "'$(NAME)' is now compiled."

$(NAME2): $(OBJS2) $(LIB)
	$(CC) $(CFLAGS) $(OBJS2) $(INCLUDES) $(LIB) -o $(NAME2)
	@echo "'$(NAME2)' is now compiled."

clean:
	@rm -rf $(OBJS) $(OBJS2)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME) $(NAME2)
	@make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
