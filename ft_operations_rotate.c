/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:07:32 by bdayakli          #+#    #+#             */
/*   Updated: 2026/03/30 17:07:32 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_rotate(t_stack **stack)
{
	int	tmp;
	int	i;
	int	j;

	if (!stack || !*stack || !((*stack)->array))
		return (0);
	if (!ft_can_swap(*stack))
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

void	ft_ra(t_data *d)
{
	if (!(d))
		return ;
	if (ft_rotate(&(d->a)) == 0)
		return ;
	else
	{
		ft_print_op("ra");
		(d->ops).ra++;
		(d->ops).total++;
	}
}

void	ft_rb(t_data *d)
{
	if (!(d))
		return ;
	if (ft_rotate(&(d->b)) == 0)
		return ;
	else
	{
		ft_print_op("rb");
		(d->ops).rb++;
		(d->ops).total++;
	}
}

void	ft_rr(t_data *d)
{
	int	resulta;
	int	resultb;

	if (!(d))
		return ;
	resulta = ft_rotate(&(d->a));
	resultb = ft_rotate(&(d->b));
	if (resulta || resultb)
	{
		ft_print_op("rr");
		(d->ops).rr++;
		(d->ops).total++;
	}
	else
		return ;
}
