/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:58:51 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/04 13:58:51 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int     ft_get_min_value(t_stack *a)
{
	int	i;
	int	min;

	if (!a || !(a -> array) || a -> size <= 0)
		return (0);
	min = a -> array[0];
	i = 1;
	while (i < a -> size)
	{
		if (min > a -> array[i])
		{
			min = a -> array[i];
		}
		i++;
	}
	return (min);
}

int     ft_get_next_min(t_stack *a, int prev_min)
{
	int	i;
	int	next_min;
	int	trigger;

	if (!a || !(a -> array)
		|| a -> size <= 0)
		return (0);
	i = 0;
	trigger = 0;
	while (i < a -> size)
	{
		if (a -> array[i] > prev_min && trigger == 0)
		{
			trigger = 1;
			next_min = a -> array[i];
		}
		if (a -> array[i] > prev_min && trigger == 1)
			if (a -> array[i] < next_min)
				next_min = a -> array[i];
		i++;
	}
	if (trigger == 1)
		return (next_min);
	return (prev_min);
}
static void    ft_init_index(int *idx, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        idx[i] = -1;
        i++;
    }
}
static int     ft_get_min_pos(t_stack *a, int *idx)
{
    int i;
    int min;
    int pos;

    i = 0;
	pos = 0;
    min = 2147483647;
    while (i < a -> size)
    {
        if (idx[i] == -1 && a -> array[i] < min)
        {
            min = a -> array[i];
            pos = i;
        }
        i++;
    }
    return (pos);
}

void    ft_assign_index(t_stack *a)
{
    int *idx;
    int i;

    if (!a || a -> size <= 1 || !(a -> array))
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
