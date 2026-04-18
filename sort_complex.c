/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:47 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 19:46:50 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;
	int	i;

	if (!a || a->size < 2 || !(a->array))
		return (0);
	max = a->array[0];
	i = 1;
	while (i < a->size)
	{
		if (a->array[i] > max)
			max = a->array[i];
		i++;
	}
	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

static void	radix_pass(t_data *d, int bit)
{
	int	temp;
	int	i;

	if (!d || !(d->a) || !(d->b) || !((d->a)->array) || !((d->b)->array))
		return ;
	temp = (d->a)->size;
	i = 0;
	while (i < temp)
	{
		if ((((d->a)->array[0] >> bit) & 1) == 0)
			pb(d);
		else
			ra(d);
		i++;
	}
	while ((d->b)->size != 0)
	{
		pa(d);
	}
}

void	sort_complex(t_data *d)
{
	int	max_bits;
	int	bits;

	if (!d || !(d->a) || !(d->b) || !(d->b)->array || !(d->a)->array
		|| (d->a)->size <= 1 || is_sorted(d->a) == 1)
		return ;
	if (d->a->size <= 5)
	{
		sort_five(d);
		return ;
	}
	assign_index(d->a);
	max_bits = get_max_bits(d->a);
	bits = 0;
	while (bits < max_bits)
	{
		radix_pass(d, bits);
		bits++;
	}
}
