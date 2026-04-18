/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:06:19 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 19:00:10 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

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

static void	check_args_valid(char **args, t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '\0' || !is_valid_number(args[i]))
		{
			free_split(args);
			error_exit(a, b);
		}
	}
}

void	parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	char	*joined;
	char	**args;

	if (!argv || argc < 2)
		return ;
	joined = join_all_args(argv, argc, a, b);
	if (!joined)
		error_exit(a, b);
	args = ft_split(joined, ' ');
	free(joined);
	if (!args || !args[0])
	{
		free_split(args);
		error_exit(a, b);
	}
	check_args_valid(args, a, b);
	a->size = count_arguments(args);
	b->size = 0;
	allocate_stacks(a, b);
	i = -1;
	while (++i < a->size)
		a->array[i] = atoli(args[i], a, b);
	free_split(args);
	check_duplicates(a, b);
}
