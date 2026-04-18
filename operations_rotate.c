/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:47:25 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:27:13 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	int	tmp;
	int	i;
	int	j;

	if (!stack || !*stack || !((*stack)->array))
		return (0);
	if (!can_swap(*stack))
		return (0);
	j = (*stack)->size - 1;
	tmp = (*stack)->array[0];
	i = 0;
	while (i <= (*stack)->size - 2)
	{
		(*stack)->array[i] = (*stack)->array[i + 1];
		i++;
	}
	(*stack)->array[j] = tmp;
	return (1);
}

void	ra(t_data *d)
{
	if (!(d))
		return ;
	if (rotate(&(d->a)) == 0)
		return ;
	else
	{
		print_op("ra");
		(d->ops).ra++;
		(d->ops).total++;
	}
}

void	rb(t_data *d)
{
	if (!(d))
		return ;
	if (rotate(&(d->b)) == 0)
		return ;
	else
	{
		print_op("rb");
		(d->ops).rb++;
		(d->ops).total++;
	}
}

void	rr(t_data *d)
{
	int	resulta;
	int	resultb;

	if (!(d))
		return ;
	resulta = rotate(&(d->a));
	resultb = rotate(&(d->b));
	if (resulta || resultb)
	{
		print_op("rr");
		(d->ops).rr++;
		(d->ops).total++;
	}
	else
		return ;
}
