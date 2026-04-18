/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:07:08 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:26:06 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **from, t_stack **to)
{
	if (!from || !to || !(*from) || !(*to))
		return (0);
	if (!can_push(*from))
		return (0);
	if (is_full(*to))
		return (0);
	shift_up(*to);
	(*to)->array[0] = (*from)->array[0];
	shift_down(*from);
	return (1);
}

void	pa(t_data *d)
{
	if (!(d))
		return ;
	if (push(&(d->b), &(d->a)) == 0)
		return ;
	else
	{
		print_op("pa");
		(d->ops).pa++;
		(d->ops).total++;
	}
}

void	pb(t_data *d)
{
	if (!(d))
		return ;
	if (push(&(d->a), &(d->b)) == 0)
		return ;
	else
	{
		print_op("pb");
		(d->ops).pb++;
		(d->ops).total++;
	}
}
