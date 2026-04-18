/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:03:29 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/18 18:32:39 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (10);
	if (size <= 500)
		return (23);
	return (size / 10);
}

static void	push_chunks(t_data *d, int chunk)
{
	int	i;

	i = 0;
	while ((d->a)->size > 0)
	{
		if (d->a->array[0] <= i)
		{
			pb(d);
			rb(d);
			i++;
		}
		else if (d->a->array[0] <= i + chunk)
		{
			pb(d);
			i++;
		}
		else
			ra(d);
	}
}

static int	find_max_pos(t_stack *b)
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

void	sort_medium(t_data *d)
{
	int	chunk_size;
	int	max_pos;

	if (d->a->size <= 5)
	{
		sort_five(d);
		return ;
	}
	assign_index(d->a);
	chunk_size = get_chunk_size(d->a->size);
	push_chunks(d, chunk_size);
	while ((d->b)->size > 0)
	{
		max_pos = find_max_pos(d->b);
		if (max_pos <= d->b->size / 2)
			while (max_pos-- > 0)
				rb(d);
		else
		{
			max_pos = d->b->size - max_pos;
			while (max_pos-- > 0)
				rrb(d);
		}
		pa(d);
	}
}
