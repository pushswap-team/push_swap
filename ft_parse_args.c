/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:06:19 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/15 20:26:31 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_check_empty_args(char **argv, int argc, t_stack *a, t_stack *b)
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

static char	*ft_join_all_args(char **argv, int argc, t_stack *a, t_stack *b)
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

static void	ft_check_duplicates(t_stack *a, t_stack *b)
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

void	ft_parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
    int		i;
    char	*joined;
    char	**args;

    if (!argv || argc < 2)
        return ;
    joined = ft_join_all_args(argv, argc, a, b);
    if (!joined)
        ft_error_exit(a, b);
    args = ft_split(joined, ' ');
    free(joined);
    if (!args || !args[0])
	{
		free(joined);
		ft_free_split(args);
        ft_error_exit(a, b);
	}
    b->size = ft_count_arguments(args);
    ft_allocate_stacks(a, b);
    i = -1;
    while (++i < a->size)
        a->array[i] = ft_atol(args[i], a, b);
    ft_free_split(args);
    ft_check_duplicates(a, b);
}
