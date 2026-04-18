/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:08:24 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:45:13 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up(t_stack *stack)
{
	int	i;

	if (!stack || !(stack->array) || stack->capacity <= 0
		|| (stack->capacity) <= (stack->size))
		return ;
	i = stack->size - 1;
	while (i >= 0)
	{
		stack->array[i + 1] = stack->array[i];
		i--;
	}
	stack->size++;
}

void	shift_down(t_stack *stack)
{
	int	i;
	int	j;

	if (!stack || !(stack->array) || stack->capacity <= 0 || stack->size == 0)
		return ;
	i = 0;
	j = stack->size - 1;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->size--;
	stack->array[j] = 0;
}

void	print_op(char *op)
{
	int	len;

	len = 0;
	while (op[len])
		len++;
	write(1, op, len);
	write(1, "\n", 1);
}

int	can_swap(t_stack *stack)
{
	if (!stack || !(stack->array) || stack->size < 2)
		return (0);
	return (1);
}

int	can_push(t_stack *stack)
{
	if (!stack || !(stack->array) || stack->size == 0)
		return (0);
	return (1);
}
