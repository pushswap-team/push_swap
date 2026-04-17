/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:32:36 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 16:01:34 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_flag_to_strategy(const char *arg)
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

int	ft_is_flag(const char *arg)
{
	if (!arg)
		return (0);
	if (ft_strncmp("--bench", arg, sizeof("--bench")) == 0)
		return (1);
	if (ft_flag_to_strategy(arg) != -1)
		return (1);
	return (0);
}

int	ft_helper_parse_flag(const char *arg, int *forced_s, int *bench_f)
{
	if (ft_strncmp(("--bench"), (arg), sizeof("--bench")) == 0)
	{
		if (*bench_f == 1)
			return (-1);
		else
			*bench_f = 1;
	}
	else if (ft_flag_to_strategy(arg) != -1)
	{
		if (*forced_s != PS_ADAPTIVE)
			return (-1);
		*forced_s = ft_flag_to_strategy(arg);
	}
	else
		return (-1);
	return (0);
}

int	ft_parse_flags(int argc, char **argv, int *forced_s, int *bench_f)
{
	int	i;
	int	j;

	if (!argv || !forced_s || !bench_f || argc < 1)
		return (-1);
	*bench_f = 0;
	*forced_s = PS_ADAPTIVE;
	i = 1;
	while (i < argc && ft_is_flag(argv[i]))
	{
		if (ft_helper_parse_flag(argv[i], forced_s, bench_f) == -1)
			return (-1);
		i++;
	}
	j = i;
	while (j < argc)
	{
		if (ft_is_flag(argv[j]) == 1)
			return (-1);
		j++;
	}
	return (0);
}

int	ft_first_number_index(int argc, char **argv)
{
	int	i;

	if (!argv || argc < 1)
		return (-1);
	i = 1;
	while (i < argc && ft_is_flag(argv[i]))
		i++;
	return (i);
}
