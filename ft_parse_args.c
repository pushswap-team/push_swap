/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:06:19 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 01:11:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int ft_is_valid_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
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

static void check_args_valid(char **args, t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '\0' || !ft_is_valid_number(args[i]))
		{
			ft_free_split(args);
			ft_error_exit(a, b);
		}
	}
}

void ft_parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int i;
	char *joined;
	char **args;

	if (!argv || argc < 2)
		return;
	joined = ft_join_all_args(argv, argc, a, b);
	if (!joined)
		ft_error_exit(a, b);
	args = ft_split(joined, ' ');
	free(joined);
	if (!args || !args[0])
	{
		ft_free_split(args);
		ft_error_exit(a, b);
	}
	check_args_valid(args, a, b);
	a->size = ft_count_arguments(args);
	b->size = 0;
	ft_allocate_stacks(a, b);
	i = -1;
	while (++i < a->size)
		a->array[i] = ft_atol(args[i], a, b);
	ft_free_split(args);
	ft_check_duplicates(a, b);
}


