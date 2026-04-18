/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:14:44 by bdayakli          #+#    #+#             */
/*   Updated: 2026/04/18 18:52:19 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_runtime_flags(int argc, char **argv,
	int *forced_s, int *bench_f)
{
	int	result;

	if (!argc || !*argv || !bench_f || !forced_s)
		return (-1);
	result = parse_flags(argc, argv, forced_s, bench_f);
	if (result == 0)
		return (0);
	return (-1);
}

static int	init_and_parse(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		first_number;
	int		parsed_argc;
	char	**parsed_argv;

	if (argc < 2 || !argv || !a || !b)
		return (-1);
	a->array = 0;
	b->array = 0;
	a->size = 0;
	b->size = 0;
	a->capacity = 0;
	b->capacity = 0;
	first_number = first_number_index(argc, argv);
	if (first_number < 1 || first_number >= argc)
		return (-1);
	parsed_argc = argc - first_number + 1;
	parsed_argv = argv + (first_number - 1);
	parse_args(parsed_argc, parsed_argv, a, b);
	a->capacity = a->size;
	b->capacity = a->size;
	return (0);
}

static void	prepare_data(t_data *d, t_stack *a, t_stack *b, int bench_f)
{
	if (!d || !a || !b)
		return ;
	d->a = a;
	d->b = b;
	d->bench_f = bench_f;
	d->disorder = compute_disorder(a);
	d->strategy = NULL;
	d->ops = (t_opcount){0};
}

static void	cleanup(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
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
	t_stack	a;
	t_stack	b;
	t_data	d;
	int		strategy;
	int		forced_s;

	d = (t_data){0};
	a = (t_stack){0};
	b = (t_stack){0};
	if (argc < 2 || !argv)
		return (0);
	if (parse_runtime_flags(argc, argv, &forced_s, &(d.bench_f)) == -1)
		error_exit(&a, &b);
	if (init_and_parse(argc, argv, &a, &b) == -1)
		error_exit(&a, &b);
	prepare_data(&d, &a, &b, (d.bench_f));
	strategy = resolve_strategy(d.disorder, forced_s);
	if (!is_sorted(d.a))
		run_strategy(&d, strategy);
	if (d.bench_f)
		print_bench(&d, forced_s, strategy);
	cleanup(&a, &b);
	return (0);
}
