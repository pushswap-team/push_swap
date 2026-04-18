/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_halpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:22 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 19:46:26 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_empty_args(char **argv, int argc, t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == ' ')
			j++;
		if (!argv[i][j])
			error_exit(a, b);
		i++;
	}
}

char	*join_all_args(char **argv, int argc, t_stack *a, t_stack *b)
{
	char	*res;
	char	*tmp;
	int		i;

	check_empty_args(argv, argc, a, b);
	res = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		tmp = res;
		res = ft_strjoin(res, argv[i]);
		free(tmp);
		if (i + 1 < argc)
		{
			tmp = res;
			res = ft_strjoin(res, " ");
			free(tmp);
		}
		i++;
	}
	return (res);
}

void	check_duplicates(t_stack *a, t_stack *b)
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
				error_exit(a, b);
			j++;
		}
		i++;
	}
}
