/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:23:38 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 16:03:43 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_min_value(t_stack *a)
{
	int	i;
	int	min;

	i = 1;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	return (min);
}

void	ft_bring_min_to_top(t_data *d, int min_pos)
{
	int	i;

	if (min_pos <= d->a->size / 2)
	{
		i = min_pos;
		while (i-- > 0)
			ft_ra(d);
	}
	else
	{
		i = d->a->size - min_pos;
		while (i-- > 0)
			ft_rra(d);
	}
}

int	ft_get_min_pos_value(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->array[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	ft_sort_five(t_data *d)
{
	int	min;
	int	min_pos;

	while (d->a->size > 3)
	{
		min = ft_get_min_value(d->a);
		min_pos = ft_get_min_pos_value(d->a, min);
		ft_bring_min_to_top(d, min_pos);
		ft_pb(d);
	}
	ft_sort_three(d);
	while (d->b->size > 0)
		ft_pa(d);
	if (d->a->size == 2 && d->a->array[0] > d->a->array[1])
		ft_sa(d);
}
