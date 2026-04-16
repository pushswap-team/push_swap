/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:53:39 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/15 19:53:39 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_index(int *idx, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		idx[i] = -1;
		i++;
	}
}

int	ft_get_min_pos(t_stack *a, int *idx)
{
	int i;
	int min;
	int pos;

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

void	ft_assign_index(t_stack *a)
{
	int *idx;
	int i;

	if (!a || a->size <= 1 || !(a->array))
		return ;
	idx = malloc(sizeof(int) * a->size);
	if (!idx)
		return ;
	ft_init_index(idx, a->size);
	i = 0;
	while (i < a->size)
		idx[ft_get_min_pos(a, idx)] = i++;
	i = 0;
	while (i < a->size)
	{
		a->array[i] = idx[i];
		i++;
	}
	free(idx);
}
