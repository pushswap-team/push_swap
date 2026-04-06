/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:35:05 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/06 11:32:51 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long    ft_atol(const char *str, t_stacks *stacks)
{
    long    res;
    int     sign;
    int     i;

    res = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i]) 
        error_exit(stacks);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            error_exit(stacks); 
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    res *= sign;
    if (res > 2147483647 || res < -2147483648)
        error_exit(stacks);
    return (res);
}

void    check_duplicates(t_stacks *stacks)
{
    int i;
    int j;

    i = 0;
    while (i < stacks->size_a)
    {
        j = i + 1;
        while (j < stacks->size_a)
        {
            if (stacks->a[i] == stacks->a[j])
                error_exit(stacks); 
            j++;
        }
        i++;
    }
}

void    free_split(char **str)
{
    int i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void    parse_args(int argc, char **argv, t_stacks *stacks)
{
    int     i;
    char    **args;

   
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv + 1;

    i = 0;
    while (args[i])
        i++;
    stacks->size_a = i;
    stacks->size_b = 0;

    stacks->a = malloc(sizeof(int) * stacks->size_a);
    stacks->b = malloc(sizeof(int) * stacks->size_a);
    if (!stacks->a || !stacks->b)
        error_exit(stacks); 

    i = -1;
    while (++i < stacks->size_a)
        stacks->a[i] = ft_atol(args[i], stacks); 

    if (argc == 2)
        free_split(args);

    check_duplicates(stacks);
}
