/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:14:44 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/08 18:44:48 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_init_and_parse(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (!argc || !*argv || !a || !b)
		return ;
	if (argc < 2)
		ft_error_exit(a, b);
	a->array = NULL;
	b->array = NULL;
	ft_parse_args(argc, argv, a, b);
	a->capacity = a->size;
	b->capacity = a->size;
}
static void ft_prepare_data(t_data *d, t_stack *a, t_stack *b, int bench_flag)
{
	if (!d || !a || !b)
		return ;
	d->a = a;
	d->b = b;
	d->bench_flag = bench_flag;
	d->disorder = ft_compute_disorder(a);
	d->strategy = NULL;
	d->ops = (t_opcount){0};
}
static void ft_cleanup(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return;
	if (a->array || b->array)
	{
		if (a->array)
		{
			free(a->array);
			a->array = NULL;
			a->size = 0;
			a->capacity = 0;
		}
		if (b->array)
		{
			free(b->array);
			b->array = NULL;
			b->size = 0;
			b->capacity = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	
}