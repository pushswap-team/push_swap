/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_halpers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:34:39 by marvin            #+#    #+#             */
/*   Updated: 2026/04/17 16:03:02 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_check_empty_args(char **argv, int argc, t_stack *a, t_stack *b)
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
			ft_error_exit(a, b);
		i++;
	}
}

char	*ft_join_all_args(char **argv, int argc, t_stack *a, t_stack *b)
{
	char	*res;
	char	*tmp;
	int		i;

	ft_check_empty_args(argv, argc, a, b);
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
