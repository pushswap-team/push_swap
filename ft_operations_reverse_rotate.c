/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_reverse_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:07:22 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 16:01:45 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_reverse_rotate(t_stack **stack)
{
	int	tmp;
	int	i;
	int	j;

	if (!stack || !*stack || !((*stack)->array))
		return (0);
	if (!ft_can_swap(*stack))
		return (0);
	j = (*stack)->size - 1;
	tmp = (*stack)->array[j];
	i = (*stack)->size - 1;
	while (i > 0)
	{
		(*stack)->array[i] = (*stack)->array[i - 1];
		i--;
	}
	(*stack)->array[0] = tmp;
	return (1);
}

void	ft_rra(t_data *d)
{
	if (!(d))
		return ;
	if (ft_reverse_rotate(&(d->a)) == 0)
		return ;
	else
	{
		ft_print_op("rra");
		(d->ops).rra++;
		(d->ops).total++;
	}
}

void	ft_rrb(t_data *d)
{
	if (!(d))
		return ;
	if (ft_reverse_rotate(&(d->b)) == 0)
		return ;
	else
	{
		ft_print_op("rrb");
		(d->ops).rrb++;
		(d->ops).total++;
	}
}

void	ft_rrr(t_data *d)
{
	int	resulta;
	int	resultb;

	if (!(d))
		return ;
	resulta = ft_reverse_rotate(&(d->a));
	resultb = ft_reverse_rotate(&(d->b));
	if (resulta || resultb)
	{
		ft_print_op("rrr");
		(d->ops).rrr++;
		(d->ops).total++;
	}
	else
		return ;
}
