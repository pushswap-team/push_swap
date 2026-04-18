/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:32:36 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:59:07 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_to_strategy(const char *arg)
{
	if (!arg)
		return (-1);
	if (ft_strncmp(("--simple"), (arg), sizeof("--simple")) == 0)
		return (PS_SIMPLE);
	else if (ft_strncmp(("--medium"), (arg), sizeof("--medium")) == 0)
		return (PS_MEDIUM);
	else if (ft_strncmp(("--complex"), (arg), sizeof("--complex")) == 0)
		return (PS_COMPLEX);
	else if (ft_strncmp(("--adaptive"), (arg), sizeof("--adaptive")) == 0)
		return (PS_ADAPTIVE);
	return (-1);
}

static int	is_flag(const char *arg)
{
	if (!arg)
		return (0);
	if (ft_strncmp("--bench", arg, sizeof("--bench")) == 0)
		return (1);
	if (flag_to_strategy(arg) != -1)
		return (1);
	return (0);
}

static int	helper_parse_flag(const char *arg, int *forced_s, int *bench_f)
{
	if (ft_strncmp(("--bench"), (arg), sizeof("--bench")) == 0)
	{
		if (*bench_f == 1)
			return (-1);
		else
			*bench_f = 1;
	}
	else if (flag_to_strategy(arg) != -1)
	{
		if (*forced_s != PS_ADAPTIVE)
			return (-1);
		*forced_s = flag_to_strategy(arg);
	}
	else
		return (-1);
	return (0);
}

int	parse_flags(int argc, char **argv, int *forced_s, int *bench_f)
{
	int	i;
	int	j;

	if (!argv || !forced_s || !bench_f || argc < 1)
		return (-1);
	*bench_f = 0;
	*forced_s = PS_ADAPTIVE;
	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		if (helper_parse_flag(argv[i], forced_s, bench_f) == -1)
			return (-1);
		i++;
	}
	j = i;
	while (j < argc)
	{
		if (is_flag(argv[j]) == 1)
			return (-1);
		j++;
	}
	return (0);
}

int	first_number_index(int argc, char **argv)
{
	int	i;

	if (!argv || argc < 1)
		return (-1);
	i = 1;
	while (i < argc && is_flag(argv[i]))
		i++;
	return (i);
}
