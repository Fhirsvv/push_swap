# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 14:57:59 by ecortes-          #+#    #+#              #
#    Updated: 2024/07/03 15:00:10 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
SRC = check_args.c main.c push.c reverse_rotate.c rotate.c swap.c utils.c utils2.c utils3.c order.c order2.c utils4.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = push_swap

all: $(NAME)

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJS)  $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)  $(LIBFT_A)

fclean: clean
	@$(RM) $(NAME) $(B_NAME)  $(OBJS)
	@make -C $(LIBFT_DIR) fclean

re: fclean
	@make all

.PHONY: all  clean fclean re