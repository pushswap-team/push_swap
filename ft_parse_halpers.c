/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_halpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:19:14 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 16:02:14 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count_arguments(char **args)
{
	int	len;

	if (!args)
		return (0);
	len = 0;
	while (args[len])
		len++;
	return (len);
}

void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_allocate_stacks(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (a->array)
		free(a->array);
	if (b->array)
		free(b->array);
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	if (!(a->array) || !(b->array))
		ft_error_exit(a, b);
	return (1);
}

void	ft_error_exit(t_stack *a, t_stack *b)
{
	if (a && a->array)
	{
		free(a->array);
		a->array = NULL;
	}
	if (b && b->array)
	{
		free(b->array);
		b->array = NULL;
	}
	write(2, "Error\n", 6);
	exit(1);
}
