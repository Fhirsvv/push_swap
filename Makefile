SRC_DIR = ./src
SRC = check_args.c main.c push.c reverse_rotate.c rotate.c swap.c utils.c

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


GREEN='\033[32m'
GRAY='\033[2;37m'
ORANGE='\033[33m'
NONE='\033[0m'

all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@echo $(CURSIVE)$(GREEN) " - Making libft..." $(NONE)
	@make bonus -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GREEN) " - Compiling $(NAME)" $(NONE)
	@gcc $(CFLAGS) $(OBJS)  $(LIBFT) -o $(NAME)
	@echo $(CURSIVE)$(GREEN) " - Compiled" $(NONE)

B = .

clean:
	$(RM) $(OBJS)  $(LIBFT_A)

fclean: clean
	@echo $(CURSIVE)$(GREEN) " - Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME) $(B_NAME)  $(OBJS)
	@make -C $(LIBFT_DIR) fclean
	@echo $(CURSIVE)$(GREEN) " - Clean!" $(NONE)

re: fclean
	@echo $(CURSIVE)$(ORANGE) " - Compiling again..." $(NONE)
	@make all

.PHONY: all  clean fclean re