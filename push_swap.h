/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:31:55 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/04 17:17:04 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stacks
{
    int     *a;
    int     *b;
    int     size_a;
    int     size_b;
} t_stacks;


void    error_exit(t_stacks *stacks);
char    **ft_split(char const *s, char c);
long    ft_atol(const char *str, t_stacks *stacks);
void    parse_args(int argc, char **argv, t_stacks *stacks);
void    check_duplicates(t_stacks *stacks);

double  compute_disorder(int *a, int size); // aşama 3 fonskiyonu 
#endif
