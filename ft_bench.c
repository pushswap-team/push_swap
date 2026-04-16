/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:45:28 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/17 01:04:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_disorder(double disorder)
{
	int	whole;
	int	frac;

	if (disorder < 0 || disorder > 1)
	{
		write(2, "[bench] disorder invalid\n", 25);
		return ;
	}
	disorder = disorder * 100;
	whole = (int)disorder;
	frac = (int)((disorder - whole) * 100 + 0.5);
	if (frac == 100)
	{
		whole++;
		frac = 0;
	}
	write(2, "[bench] Disorder: ", 18);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac, 2);
	ft_putchar_fd('%', 2);
	ft_putchar_fd('\n', 2);
}

void	ft_print_strategy_info(int strategy, int forced_s)
{
	const char	*name;
	const char	*complexity;
	int			size_name;
	int			size_complexity;

	name = ft_strategy_name(strategy);
	complexity = ft_strategy_complexity(forced_s);
	size_name = ft_strlen(name);
	size_complexity = ft_strlen(complexity);
	write(2, "[bench] Strategy: ", 18);
	write(2, name, size_name);
	write(2, " / ", 3);
	write(2, complexity, size_complexity);
	write(2, "\n", 1);
}

void	ft_print_op_line(const char *label, int value)
{
	int	label_size;

	label_size = ft_strlen(label);
	write(2, label, label_size);
	write(2, ": ", 2);
	ft_putnbr_fd(value, 2);
}

void	ft_print_op_breakdown(const t_opcount *ops)
{
	if (!ops)
		return ;
	write(2, "[bench] ", 8);
	ft_print_op_line(("sa"), (ops->sa));
	ft_print_op_line((" sb"), (ops->sb));
	ft_print_op_line((" ss"), (ops->ss));
	ft_print_op_line((" pa"), (ops->pa));
	ft_print_op_line((" pb"), (ops->pb));
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	ft_print_op_line(("ra"), (ops->ra));
	ft_print_op_line((" rb"), (ops->rb));
	ft_print_op_line((" rr"), (ops->rr));
	ft_print_op_line((" rra"), (ops->rra));
	ft_print_op_line((" rrb"), (ops->rrb));
	ft_print_op_line((" rrr"), (ops->rrr));
	write(2, "\n", 1);
}

void	ft_print_bench(const t_data *d, int strategy, int forced_s)
{
	if (!d)
		return ;
	ft_print_disorder(d->disorder);
	ft_print_strategy_info(strategy, forced_s);
	write(2, "[bench] Total ops: ", 19);
	ft_putnbr_fd((d->ops).total, 2);
	write(2, "\n", 1);
	ft_print_op_breakdown(&(d->ops));
}
