/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:50:14 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/15 13:03:50 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

	i = 0;
	res = 0;
	sign = ft_sign_halper((char *)str);
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	if (!str[i])
		ft_error_exit(a, b);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error_exit(a, b);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		ft_error_exit(a, b);
	return (res);
}

void	ft_check_duplicates(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->array[i] == a->array[j])
				ft_error_exit(a, b);
			j++;
		}
		i++;
	}
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	argv = ft_get_args_source(argv, argc);
	if (!argv)
		return ;
	a->size = ft_count_arguments(argv);
	b->size = 0;
	ft_allocate_stacks(a, b);
	i = 0;
	while (i < a->size)
	{
		a->array[i] = ft_atol(argv[i], a, b);
		i++;
	}
	if (argc == 2)
		ft_free_split(argv);
	ft_check_duplicates(a, b);
}
