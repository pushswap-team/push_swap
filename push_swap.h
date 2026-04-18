/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:03:07 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/18 19:05:11 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define PS_ADAPTIVE 0
# define PS_SIMPLE 1
# define PS_MEDIUM 2
# define PS_COMPLEX 3

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_opcount
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_opcount;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_opcount	ops;
	double		disorder;
	int			bench_f;
	char		*strategy;
}	t_data;

void		parse_args(int argc, char **argv, t_stack *a, t_stack *b);
long		atoli(const char *str, t_stack *a, t_stack *b);
char		*join_all_args(char **argv, int argc, t_stack *a, t_stack *b);
void		check_duplicates(t_stack *a, t_stack *b);
int			first_number_index(int argc, char **argv);
double		compute_disorder(t_stack *a);
int			resolve_strategy(double disorder, int forced_strategy);
void		run_strategy(t_data *d, int strategy);
int			parse_flags(int argc, char **argv, int *forced_s, int *bench_f);
void		assign_index(t_stack *a);
const char	*strategy_name(int strategy);
const char	*strategy_complexity(int strategy);
void		sort_simple(t_data *d);
void		sort_three(t_data *d);
void		sort_five(t_data *d);
void		sort_medium(t_data *d);
void		sort_complex(t_data *d);
void		pa(t_data *d);
void		pb(t_data *d);
void		sa(t_data *d);
void		sb(t_data *d);
void		ss(t_data *d);
void		ra(t_data *d);
void		rb(t_data *d);
void		rr(t_data *d);
void		rra(t_data *d);
void		rrb(t_data *d);
void		rrr(t_data *d);
void		shift_up(t_stack *stack);
void		shift_down(t_stack *stack);
int			is_sorted(t_stack *stack);
int			is_full(t_stack *stack);
int			can_swap(t_stack *stack);
int			can_push(t_stack *stack);
int			get_min_pos(t_stack *a, int *idx);
void		print_bench(const t_data *d, int strategy, int resolved_s);
void		print_op(char *op);
int			count_arguments(char **args);
void		free_split(char **str);
int			allocate_stacks(t_stack *a, t_stack *b);
void		error_exit(t_stack *a, t_stack *b);
int			main(int argc, char **argv);

#endif