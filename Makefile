# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/23 14:10:16 by bayram-seve       #+#    #+#              #
#    Updated: 2026/04/13 16:01:04 by bdayakli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ft_push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = ft_strategy.c \
			ft_adaptive.c \
			ft_bench.c \
			ft_flags.c \
			ft_parse.c \
			  ft_parse_halpers.c \
			  main.c \
			  ft_index.c \
			  ft_sort_simple.c \
			  ft_sort_medium.c \
			  ft_sort_complex.c \
			  ft_operations_push.c \
			  ft_operations_rotate.c \
			  ft_operations_reverse_rotate.c \
			  ft_operations_swap.c \
			  ft_stack_utils.c \
			  ft_stack_utils2.c \

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c ft_push_swap.h	
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re