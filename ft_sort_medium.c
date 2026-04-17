/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:03:29 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/17 16:03:32 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_chunk_size(int size)
{
	if (size <= 100)
		return (10);
	if (size <= 500)
		return (23);
	return (size / 10);
}

void	ft_push_chunks(t_data *d, int chunk)
{
	int	i;

	i = 0;
	while ((d->a)->size > 0)
	{
		if (d->a->array[0] <= i)
		{
			ft_pb(d);
			ft_rb(d);
			i++;
		}
		else if (d->a->array[0] <= i + chunk)
		{
			ft_pb(d);
			i++;
		}
		else
			ft_ra(d);
	}
}

int	ft_find_max_pos(t_stack *b)
{
	int	max_val;
	int	max_pos;
	int	i;

	i = 0;
	max_val = b->array[0];
	max_pos = 0;
	while (i < b->size)
	{
		if (b->array[i] > max_val)
		{
			max_val = b->array[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	ft_sort_medium(t_data *d)
{
	int	chunk_size;
	int	max_pos;

	if (d->a->size <= 5)
	{
		ft_sort_five(d);
		return ;
	}
	ft_assign_index(d->a);
	chunk_size = ft_get_chunk_size(d->a->size);
	ft_push_chunks(d, chunk_size);
	while ((d->b)->size > 0)
	{
		max_pos = ft_find_max_pos(d->b);
		if (max_pos <= d->b->size / 2)
			while (max_pos-- > 0)
				ft_rb(d);
		else
		{
			max_pos = d->b->size - max_pos;
			while (max_pos-- > 0)
				ft_rrb(d);
		}
		ft_pa(d);
	}
}
