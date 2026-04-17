/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:03:18 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/17 16:03:25 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_max_bits(t_stack *a)
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

void	ft_radix_pass(t_data *d, int bit)
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
			ft_pb(d);
		else
			ft_ra(d);
		i++;
	}
	while ((d->b)->size != 0)
	{
		ft_pa(d);
	}
}

void	ft_sort_complex(t_data *d)
{
	int	max_bits;
	int	bits;

	if (!d || !(d->a) || !(d->b) || !(d->b)->array || !(d->a)->array
		|| (d->a)->size <= 1 || ft_is_sorted(d->a) == 1)
		return ;
	if (d->a->size <= 5)
	{
		ft_sort_five(d);
		return ;
	}
	ft_assign_index(d->a);
	max_bits = ft_get_max_bits(d->a);
	bits = 0;
	while (bits < max_bits)
	{
		ft_radix_pass(d, bits);
		bits++;
	}
}
