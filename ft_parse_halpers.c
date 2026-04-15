/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_halpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:19:14 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/15 20:25:59 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count_arguments(char **args)
{
	int	len;

	if (!*args || !(args))
		return (0);
	len = 0;
	while (args[len])
	{
		len++;
	}
	return (len);
}

void	ft_free_split(char **str)
{
	int	i;

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
int	ft_allocate_stacks(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	a->array = NULL;
	b->array = NULL;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	if (!(a->array) || !(b->array))
		ft_error_exit(a, b);
	return (1);
}

void	ft_error_exit(t_stack *a, t_stack *b)
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
