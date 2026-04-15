/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:08:15 by bdayakli          #+#    #+#             */
/*   Updated: 2026/03/30 17:08:15 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_full(t_stack *stack)
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

static int	ft_is_empty(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (1);
	else
		return (0);
}

static void	ft_free_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->array)
	{
		free ((*stack)->array);
		(*stack)->array = 0;
	}
	(*stack)->size = 0;
	(*stack)->capacity = 0;
	free (*stack);
	*stack = 0;
}

static int	ft_init_stack(t_stack *stack, int capacity)
{
	if (!stack || capacity <= 0)
		return (0);
	stack->array = malloc(sizeof(int) * capacity);
	if (!(stack->array))
		return (0);
	stack->size = 0;
	stack->capacity = capacity;
	return (1);
}

int	ft_is_sorted(t_stack *stack)
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
