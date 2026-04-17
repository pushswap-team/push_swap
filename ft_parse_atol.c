/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_atol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:50:14 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/17 16:02:07 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_is_digit_str(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_get_sign(const char *str)
{
	if (str[0] == '-')
		return (-1);
	return (1);
}

static long	ft_atol_core(const char *str, t_stack *a, t_stack *b)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error_exit(a, b);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

long	ft_atol(const char *str, t_stack *a, t_stack *b)
{
	long	res;
	int		sign;
	int		i;

	if (!str)
		ft_error_exit(a, b);
	sign = ft_get_sign(str);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (ft_strlen(&str[i]) >= 19)
		ft_error_exit(a, b);
	if (!ft_is_digit_str(&str[i]))
		ft_error_exit(a, b);
	res = ft_atol_core(&str[i], a, b);
	if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
		ft_error_exit(a, b);
	return (res * sign);
}
