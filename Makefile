# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 21:43:40 by bdayakli          #+#    #+#              #
#    Updated: 2026/04/18 21:43:43 by bdayakli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = strategy.c \
			adaptive.c \
			bench.c \
			flags.c \
			parse_args.c \
			parse_atoli.c \
			parse_halpers.c \
			parse_halpers2.c \
			main.c \
			index.c \
			sort_simple.c \
			sort_medium.c \
			sort_complex.c \
			operations_push.c \
			operations_rotate.c \
			operations_reverse_rotate.c \
			operations_swap.c \
			stack_utils.c \
			stack_utils2.c \
			sort_small.c \

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
