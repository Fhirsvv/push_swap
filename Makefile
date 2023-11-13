SRC_DIR = ./src
SRC = check_args.c main.c push.c reverse_rotate.c rotate.c swap.c utils.c utils2.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
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

B = .

clean:
	$(RM) $(OBJS)  $(LIBFT_A)

fclean: clean
	@$(RM) $(NAME) $(B_NAME)  $(OBJS)
	@make -C $(LIBFT_DIR) fclean

re: fclean
	@make all

.PHONY: all  clean fclean re