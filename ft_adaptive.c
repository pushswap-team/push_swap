/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:16:44 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/09 18:16:52 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

double		ft_compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;
	
	if (a == 0 || a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->array[i] > a->array[j])
				mistakes++;
			j++;
			total_pairs++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return(((double)mistakes) / ((double)total_pairs));
}
