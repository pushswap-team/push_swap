/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:07:08 by bdayakli          #+#    #+#             */
/*   Updated: 2026/03/30 17:07:08 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push(t_stack **from, t_stack **to)
{
	if (!from || !to || !(*from) || !(*to))
		return (0);
	if (!ft_can_push(*from))
		return (0);
	if (ft_is_full(*to))
		return (0);
	ft_shift_up(*to);
	(*to)->array[0] = (*from)->array[0];
	ft_shift_down(*from);
	return (1);
}

void	ft_pa(t_data *d)
{
	if (!(d))
		return ;
	if (ft_push(&(d->b), &(d->a)) == 0)
		return ;
	else
		ft_print_op("pa");
}

void	ft_pb(t_data *d)
{
	if (!(d))
		return ;
	if (ft_push(&(d->a), &(d->b)) == 0)
		return ;
	else
		ft_print_op("pb");
}
