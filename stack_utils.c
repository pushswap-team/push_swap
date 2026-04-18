/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:03:45 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/18 18:44:49 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_full(t_stack *stack)
{
	if (!stack)
		return (0);
	if (stack->capacity <= 0)
		return (0);
	if (stack->size >= stack->capacity)
		return (1);
	else
		return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 1)
		return (1);
	i = 0;
	while (i < (stack->size) - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
