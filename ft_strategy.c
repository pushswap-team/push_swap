/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:45:12 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/13 17:25:17 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_select_adaptive_strategy(double disorder)
{
	if (disorder >= 0.00 && disorder < 0.25)
		return (PS_SIMPLE);
	else if (disorder >= 0.25 && disorder < 0.70)
		return (PS_MEDIUM);
	else if (disorder >= 0.70 && disorder <= 1.00)
		return (PS_COMPLEX);
	return (PS_COMPLEX);
}

int	ft_resolve_strategy(double disorder, int forced_strategy)
{
	int	result;

	if (forced_strategy != PS_ADAPTIVE)
		return (forced_strategy);
	else
		result = ft_select_adaptive_strategy(disorder);
	return (result);
}

void	ft_run_strategy(t_data *d, int strategy)
{
	if (!d)
		return ;
	if (strategy == PS_SIMPLE)
		ft_sort_simple(d);
	else if (strategy == PS_MEDIUM)
		ft_sort_medium(d);
	else
		ft_sort_complex(d);
}

const char	*ft_strategy_name(int strategy)
{
	if (strategy == PS_SIMPLE)
		return ("simple");
	if (strategy == PS_MEDIUM)
		return ("medium");
	if (strategy == PS_COMPLEX)
		return ("complex");
	if (strategy == PS_ADAPTIVE)
		return ("adaptive");
	return ("unknown");
}

const char	*ft_strategy_complexity(int strategy)
{
	if (strategy == PS_SIMPLE)
		return ("O(n^2)");
	if (strategy == PS_MEDIUM)
		return ("chunk-based");
	if (strategy == PS_COMPLEX)
		return ("radix-based");
	if (strategy == PS_ADAPTIVE)
		return ("hybrid");
	return ("unknown");
}
