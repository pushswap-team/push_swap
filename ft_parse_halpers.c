/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_halpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:06:19 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/07 14:51:21 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	**ft_get_args_source(char **argv, int argc)
{
	char	**res;
	
	if ( argv == NULL || argc < 2)
		return (NULL);
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		return (res);
	}
	else if (argc > 2)
	{
		res = argv + 1;
		return (res);
	}
	return (NULL);
}

int	ft_count_arguments(char	**args)
{
	int	len;
	
	if (!*args)
		return (0);
	len = 0;
	while (args[len])
	{
		len++;
	}
	return (len);
}

int	ft_allocate_stacks(t_stack *a, t_stack *b)
{
	if (!a || !b)
		 return (0);
	a->array = NULL;
	b->array = NULL;
	a->array = malloc(sizeof(int) * a->size);
    b->array = malloc(sizeof(int) * b->size);
    if (!a->array || !b->array)
        ft_error_exit(a, b);
	return (1);
}
void    ft_error_exit(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    if (a->array || b->array)
    {
        if (a->array)
            free(a->array);
        if (b->array)
            free(b->array);
    }
    write(2, "Error\n", 6);
    exit(1);
}

void	ft_parse_and_validate(t_stack *a, t_stack *b, char **args, int is_split, int argc)
{
	
}
