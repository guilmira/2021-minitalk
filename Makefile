# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 15:28:36 by guilmira          #+#    #+#              #
#    Updated: 2021/09/23 12:04:43 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME	= server
NAME2	= client
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#-g3 -fsanitize=address

#atencion al _di-cl-r
#--------------------------------------------------------------------------------------------------------------LIBS
GNL_DIR		= ./get_next_line
GNL			= $(GNL_DIR)/gnl.a
PF_DIR		= ./ft_printf
PF			= $(PF_DIR)/libftprintf.a
LIB_DIR		= $(PF_DIR)/libft_submodule
LIB			= $(LIB_DIR)/libft.a

INCLUDES	= -I ./0includes -I ./get_next_line/0includes -I ./ft_printf/0includes -I ./ft_printf/libft_submodule/0includes
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		= 0server.c
SRCS2		= 1client.c
OBJS		= $(SRCS:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
OBJS_DIR	= ./0objects
#--------------------------------------------------------------------------------------------------------------RULES
all: gnl ft_printf $(NAME)

gnl:
	@make -C $(GNL_DIR)

$(PF):
	@make -C $(PF_DIR)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(GNL) $(PF)
	@$(CC) $(FLAGS) $(OBJS) $(INCLUDES) $(GNL) $(PF) $(LIB) -o $(NAME)
	@mv $(OBJS) ./0objects
	@echo "Compiled '$(NAME)'."

$(NAME2): $(OBJS2) $(GNL) $(PF) $(LIB)
	@$(CC) $(FLAGS) $(OBJS2) $(INCLUDES) $(GNL) $(PF) $(LIB) -o $(NAME2)
	@mv $(OBJS2) ./0objects
	@echo "Compiled '$(NAME2)'."

test: $(GNL) $(PF) $(LIB)
	@$(CC) $(FLAGS) mainn.c $(INCLUDES) $(GNL) $(PF) $(LIB) -o test_guil && ./test_guil

ex: $(NAME) $(NAME2)
	./$(NAME)
PARAM = PID 2
lance:
	./$(NAME) $(PARAM)

clean:
	@rm -rf $(OBJS_DIR)/*.o
	@rm -rf $(OBJS_DIR)/*.o
	make clean -C $(GNL_DIR)
	make clean -C $(PF_DIR)

ey:
	rm -rf $(OBJS_DIR)/$(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME2)
	make fclean -C $(GNL_DIR)
	make fclean -C $(PF_DIR)

re: fclean all

.PHONY: all clean fclean re
