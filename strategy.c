/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:45:12 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:57:29 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	select_adaptive_strategy(double disorder)
{
	if (disorder >= 0.0 && disorder < 0.2)
		return (PS_SIMPLE);
	else if (disorder >= 0.2 && disorder < 0.5)
		return (PS_MEDIUM);
	else if (disorder >= 0.5 && disorder <= 1.0)
		return (PS_COMPLEX);
	return (PS_COMPLEX);
}

int	resolve_strategy(double disorder, int forced_strategy)
{
	int	result;

	if (forced_strategy != PS_ADAPTIVE)
		return (forced_strategy);
	else
		result = select_adaptive_strategy(disorder);
	return (result);
}

void	run_strategy(t_data *d, int strategy)
{
	if (!d)
		return ;
	if (strategy == PS_SIMPLE)
		sort_simple(d);
	else if (strategy == PS_MEDIUM)
		sort_medium(d);
	else
		sort_complex(d);
}

const char	*strategy_name(int strategy)
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

const char	*strategy_complexity(int strategy)
{
	if (strategy == PS_SIMPLE)
		return ("O(n^2)");
	if (strategy == PS_MEDIUM)
		return ("O(n√n)");
	if (strategy == PS_COMPLEX)
		return ("O(n log n)");
	return ("unknown");
}
