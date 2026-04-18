/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atoli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:50:14 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/18 19:13:25 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit_str(const char *str)
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

static int	get_sign(const char *str)
{
	if (str[0] == '-')
		return (-1);
	return (1);
}

static long	atol_core(const char *str, t_stack *a, t_stack *b)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit(a, b);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

long	atoli(const char *str, t_stack *a, t_stack *b)
{
	long	res;
	int		sign;
	int		i;

	if (!str)
		error_exit(a, b);
	sign = get_sign(str);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (ft_strlen(&str[i]) >= 19)
		error_exit(a, b);
	if (!is_digit_str(&str[i]))
		error_exit(a, b);
	res = atol_core(&str[i], a, b);
	if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
		error_exit(a, b);
	return (res * sign);
}
