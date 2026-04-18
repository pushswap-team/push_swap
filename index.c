/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:47:36 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 19:06:56 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_index(int *idx, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		idx[i] = -1;
		i++;
	}
}

int	get_min_pos(t_stack *a, int *idx)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	pos = 0;
	min = 2147483647;
	while (i < a->size)
	{
		if (idx[i] == -1 && a->array[i] < min)
		{
			min = a->array[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	assign_index(t_stack *a)
{
	int	*idx;
	int	i;

	if (!a || a->size <= 1 || !(a->array))
		return ;
	idx = malloc(sizeof(int) * a->size);
	if (!idx)
		return ;
	init_index(idx, a->size);
	i = 0;
	while (i < a->size)
		idx[get_min_pos(a, idx)] = i++;
	i = 0;
	while (i < a->size)
	{
		a->array[i] = idx[i];
		i++;
	}
	free(idx);
}
