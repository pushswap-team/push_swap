/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:00:22 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/05 17:00:22 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int     ft_find_min_pos(t_stack *a)
{
	int	min_value;
	int	min_pos;
	int	i;

	if (!a ||  !(a -> array) || a -> size <= 0)
		return (0);
	min_value = a -> array[0];
	min_pos = 0;
	i = 1;
	while (i < a -> size)
	{
		if (a -> array[i] < min_value)
		{
			min_value = a -> array[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void    ft_push_min_to_b(t_stack *a, t_stack *b)
{

}

void    ft_sort_simple(t_stack *a, t_stack *b)
{

}

