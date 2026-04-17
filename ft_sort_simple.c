/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:00:22 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 16:03:38 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_min_pos(t_stack *a)
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

void	ft_push_min_to_b(t_data *d)
{
	int	min_pos;

	if (!d || !d->a || ft_can_push(d->a) == 0)
		return ;
	min_pos = ft_find_min_pos(d->a);
	while (min_pos != 0)
	{
		if (min_pos <= (((d->a)->size) / 2))
			ft_ra(d);
		else
			ft_rra(d);
		min_pos = ft_find_min_pos(d->a);
	}
	ft_pb(d);
}

void	ft_sort_three(t_data *d)
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
		ft_sa(d);
	if (x > y && y > z)
	{
		ft_sa(d);
		ft_rra(d);
	}
	if (x < y && y > z && x < z)
	{
		ft_sa(d);
		ft_ra(d);
	}
	if (x > y && y < z && x > z)
		ft_ra(d);
	if (x < y && y > z && x > z)
		ft_rra(d);
}

void	ft_sort_simple(t_data *d)
{
	if (!d || !(d->a) || !(d->b) || !((d->a)->array) || !((d->b)->array)
		|| ft_is_sorted(d->a) == 1)
		return ;
	if ((d->a)->size <= 1)
		return ;
	else if ((d->a)->size == 2)
	{
		if ((d->a)->array[0] < (d->a)->array[1])
			return ;
		else
			return (ft_sa(d));
	}
	else if ((d->a)->size == 3)
		return (ft_sort_three(d));
	while ((d->a)->size > 3)
		ft_push_min_to_b(d);
	ft_sort_three(d);
	while ((d->b)->size > 0)
		ft_pa(d);
}
