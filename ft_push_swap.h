/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:03:07 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/17 16:03:12 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

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

/* --- 1. Initialization & Parsing --- */
int			ft_init_and_parse(int argc, char **argv, t_stack *a, t_stack *b);
void		ft_parse_args(int argc, char **argv, t_stack *a, t_stack *b);
long		ft_atol(const char *str, t_stack *a, t_stack *b);
long		ft_atol_helper(const char *str, long res, t_stack *a, t_stack *b);
char		*ft_join_all_args(char **argv, int argc, t_stack *a, t_stack *b);
void		ft_check_duplicates(t_stack *a, t_stack *b);
void		ft_check_empty_args(char **argv, int argc, t_stack *a, t_stack *b);
int			ft_parse_flags(int argc, char **argv, int *forced_s, int *bench_f);
int			ft_parse_runtime_flags(int argc, char **argv, int *forced_s,
				int *bench_f);
int			ft_first_number_index(int argc, char **argv);
int			ft_is_flag(const char *arg);
int			ft_helper_parse_flag(const char *arg, int *forced_s, int *bench_f);
int			ft_flag_to_strategy(const char *arg);
int			ft_sign_halper(char *str);

/* --- 2. Strategy & Analysis --- */
void		ft_prepare_data(t_data *d, t_stack *a, t_stack *b, int bench_f);
double		ft_compute_disorder(t_stack *a);
int			ft_resolve_strategy(double disorder, int forced_strategy);
int			ft_select_adaptive_strategy(double disorder);
void		ft_run_strategy(t_data *d, int strategy);
void		ft_assign_index(t_stack *a);
void		ft_init_index(int *idx, int size);
const char	*ft_strategy_name(int strategy);
const char	*ft_strategy_complexity(int strategy);

/* --- 3. Sorting Algorithms --- */
void		ft_sort_simple(t_data *d);
void		ft_sort_three(t_data *d);
void		ft_sort_five(t_data *d);
void		ft_sort_medium(t_data *d);
void		ft_sort_complex(t_data *d);
void		ft_radix_pass(t_data *d, int bit);
void		ft_push_chunks(t_data *d, int chunk);

/* --- 4. Operations (Mandatory) --- */
void		ft_pa(t_data *d);
void		ft_pb(t_data *d);
void		ft_sa(t_data *d);
void		ft_sb(t_data *d);
void		ft_ss(t_data *d);
void		ft_ra(t_data *d);
void		ft_rb(t_data *d);
void		ft_rr(t_data *d);
void		ft_rra(t_data *d);
void		ft_rrb(t_data *d);
void		ft_rrr(t_data *d);

/* --- 5. Low Level Mechanics --- */
int			ft_push(t_stack **from, t_stack **to);
int			ft_swap(t_stack **stack);
int			ft_rotate(t_stack **stack);
int			ft_reverse_rotate(t_stack **stack);
void		ft_shift_up(t_stack *stack);
void		ft_shift_down(t_stack *stack);

/* --- 6. Stack Utils & Helpers --- */
int			ft_is_sorted(t_stack *stack);
int			ft_is_full(t_stack *stack);
int			ft_can_swap(t_stack *stack);
int			ft_can_push(t_stack *stack);
int			ft_find_min_pos(t_stack *a);
int			ft_find_max_pos(t_stack *b);
int			ft_get_min_value(t_stack *a);
int			ft_get_min_pos(t_stack *a, int *idx);
int			ft_get_min_pos_value(t_stack *a, int value);
void		ft_bring_min_to_top(t_data *d, int min_pos);
void		ft_push_min_to_b(t_data *d);
int			ft_get_chunk_size(int size);
int			ft_get_max_bits(t_stack *a);

/* --- 7. Benchmarking & Cleanup --- */
void		ft_print_bench(const t_data *d, int strategy, int resolved_s);
void		ft_print_op_breakdown(const t_opcount *ops);
void		ft_print_disorder(double disorder);
void		ft_print_strategy_info(int strategy, int resolved_s);
void		ft_print_op_line(const char *label, int value);
void		ft_print_op(char *op);
int			ft_count_arguments(char **args);
void		ft_free_split(char **str);
int			ft_allocate_stacks(t_stack *a, t_stack *b);
void		ft_cleanup(t_stack *a, t_stack *b);
void		ft_error_exit(t_stack *a, t_stack *b);

int			main(int argc, char **argv);

#endif