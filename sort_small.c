/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:23:38 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 19:35:12 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_value(t_stack *a)
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

static void	bring_min_to_top(t_data *d, int min_pos)
{
	int	i;

	if (min_pos <= (d->a)->size / 2)
	{
		i = min_pos;
		while (i-- > 0)
			ra(d);
	}
	else
	{
		i = (d->a)->size - min_pos;
		while (i-- > 0)
			rra(d);
	}
}

static int	get_min_pos_value(t_stack *a, int value)
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

void	sort_five(t_data *d)
{
	int	min;
	int	min_pos;

	while ((d->a)->size > 3)
	{
		min = get_min_value(d->a);
		min_pos = get_min_pos_value(d->a, min);
		bring_min_to_top(d, min_pos);
		pb(d);
	}
	sort_three(d);
	while ((d->b)->size > 0)
		pa(d);
	if ((d->a)->size == 2 && (d->a)->array[0] > (d->a)->array[1])
		sa(d);
}
