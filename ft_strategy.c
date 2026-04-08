/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:45:12 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/08 17:41:35 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_select_adaptive_strategy(double disorder)
{
// Disorder’a göre strategy seçer.
}
int	ft_resolve_strategy(double disorder, int forced_strategy)
{
//Zorlanmış strategy varsa onu, yoksa adaptive sonucu döner.
}
void	ft_run_strategy(t_data *d, int strategy)
{
//Seçilen strategy’ye göre sort fonksiyonunu çağırır.
}
const char	*ft_strategy_name(int strategy)
{
//Strategy adını döner.
}
const char	*ft_strategy_complexity(int strategy)
{
// Strategy complexity metnini döner.
}