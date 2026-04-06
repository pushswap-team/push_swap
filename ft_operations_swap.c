/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:07:41 by bdayakli          #+#    #+#             */
/*   Updated: 2026/03/30 17:07:41 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_swap(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !((*stack)->array))
		return (0);
	if (!ft_can_swap(*stack))
		return (0);
	tmp = 0;
	tmp = (*stack)->array[0];
	(*stack)->array[0] = (*stack)->array[1];
	(*stack)->array[1] = tmp;
	return (1);
}

void	ft_sa(t_data *d)
{
	if (!(d))
		return ;
	if (ft_swap(&(d->a)) == 0)
		return ;
	else
		ft_print_op("sa");
}

void	ft_sb(t_data *d)
{
	if (!(d))
		return ;
	if (ft_swap(&(d->b)) == 0)
		return ;
	else
		ft_print_op("sb");
}

void	ft_ss(t_data *d)
{
	int	resulta;
	int	resultb;

	if (!(d))
		return ;
	resulta = ft_swap(&(d->a));
	resultb = ft_swap(&(d->b));
	if (resulta || resultb)
		ft_print_op("ss");
	else
		return ;
}
