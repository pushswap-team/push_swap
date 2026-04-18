/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:00:22 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:56:08 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int	min_value;
	int	min_pos;
	int	i;

	if (!a || !(a->array) || a->size <= 0)
		return (0);
	min_value = a->array[0];
	min_pos = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->array[i] < min_value)
		{
			min_value = a->array[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_data *d)
{
	int	min_pos;

	if (!d || !d->a || can_push(d->a) == 0)
		return ;
	min_pos = find_min_pos(d->a);
	while (min_pos != 0)
	{
		if (min_pos <= (((d->a)->size) / 2))
			ra(d);
		else
			rra(d);
		min_pos = find_min_pos(d->a);
	}
	pb(d);
}

void	sort_three(t_data *d)
{
	int	x;
	int	y;
	int	z;

	if (!d || !(d->a) || (d->a)->size != 3 || !(d->a)->array)
		return ;
	x = (d->a)->array[0];
	y = (d->a)->array[1];
	z = (d->a)->array[2];
	if (x > y && y < z && x < z)
		sa(d);
	if (x > y && y > z)
	{
		sa(d);
		rra(d);
	}
	if (x < y && y > z && x < z)
	{
		sa(d);
		ra(d);
	}
	if (x > y && y < z && x > z)
		ra(d);
	if (x < y && y > z && x > z)
		rra(d);
}

void	sort_simple(t_data *d)
{
	if (!d || !(d->a) || !(d->b) || !((d->a)->array) || !((d->b)->array)
		|| is_sorted(d->a) == 1)
		return ;
	if ((d->a)->size <= 1)
		return ;
	else if ((d->a)->size == 2)
	{
		if ((d->a)->array[0] < (d->a)->array[1])
			return ;
		else
			sa(d);
	}
	else if ((d->a)->size == 3)
		sort_three(d);
	while ((d->a)->size > 3)
		push_min_to_b(d);
	sort_three(d);
	while ((d->b)->size > 0)
		pa(d);
}
