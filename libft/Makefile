# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 19:22:20 by ecortes-          #+#    #+#              #
#    Updated: 2023/11/21 17:36:54 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isprint.c  ft_putchar_fd.c ft_strjoin.c ft_strrchr.c ft_putendl_fd.c ft_strlcat.c ft_strtrim.c ft_bzero.c  \
ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_itoa.c ft_substr.c ft_calloc.c  ft_memcmp.c ft_putstr_fd.c ft_tolower.c ft_isalnum.c  ft_split.c \
ft_strlen.c ft_toupper.c ft_isalpha.c  ft_memcpy.c ft_strchr.c ft_strmapi.c ft_isascii.c ft_memmove.c ft_strdup.c \
ft_strncmp.c ft_isdigit.c  ft_memset.c ft_striteri.c ft_strnstr.c ft_str.c ft_ptr.c ft_printf.c ft_print_format.c ft_dig.c ft_char.c \

BONUS = ft_lstnew_bonus.c ft_lstclear_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
        ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re