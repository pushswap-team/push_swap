/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_atol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:50:14 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/15 20:26:47 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static long	ft_atol_helper(const char *str, long res, t_stack *a, t_stack *b)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error_exit(a, b);
		if (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10 
			&& (str[i]- '0') > LLONG_MAX % 10))
			ft_error_exit(a, b);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

static int	ft_sign_halper(char *str)
{
	int	sign;

	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
	}
	return (sign);
}

long	ft_atol(const char *str, t_stack *a, t_stack *b)
{
	long	res;
	int		sign;
	int		i;

	if (!str)
		ft_error_exit(a, b);
	i = 0;
	res = 0;
	sign = ft_sign_halper((char *)str);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		ft_error_exit(a, b);
	res = ft_atol_helper(&str[i], res, a, b);
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		ft_error_exit(a, b);
	return (res);
}


