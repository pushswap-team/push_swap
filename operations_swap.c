/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:07:41 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:27:56 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !((*stack)->array))
		return (0);
	if (!can_swap(*stack))
		return (0);
	tmp = 0;
	tmp = (*stack)->array[0];
	(*stack)->array[0] = (*stack)->array[1];
	(*stack)->array[1] = tmp;
	return (1);
}

void	sa(t_data *d)
{
	if (!(d))
		return ;
	if (swap(&(d->a)) == 0)
		return ;
	else
	{
		print_op("sa");
		(d->ops).sa++;
		(d->ops).total++;
	}
}

void	sb(t_data *d)
{
	if (!(d))
		return ;
	if (swap(&(d->b)) == 0)
		return ;
	else
	{
		print_op("sb");
		(d->ops).sb++;
		(d->ops).total++;
	}
}

void	ss(t_data *d)
{
	int	resulta;
	int	resultb;

	if (!(d))
		return ;
	resulta = swap(&(d->a));
	resultb = swap(&(d->b));
	if (resulta || resultb)
	{
		print_op("ss");
		(d->ops).ss++;
		(d->ops).total++;
	}
	else
		return ;
}
