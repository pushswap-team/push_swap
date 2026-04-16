/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/04/15 20:55:22 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/15 20:55:22 by bayseven         ###   ########.fr       */
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
	int *array;   // Dinamik array, sayıları tutar
	int size;     // Şu an kaç eleman var (top index = size-1)
	int capacity; // Maksimum kapasite (realloc için)
} t_stack;

typedef struct s_opcount
{
	int sa;
	int sb;
	int ss; // Swap'ler
	int pa;
	int pb; // Push'lar
	int ra;
	int rb;
	int rr; // Rotate'ler
	int rra;
	int rrb;
	int rrr;   // Reverse rotate'ler
	int total; // Toplam operasyon
} t_opcount;

typedef struct s_data
{
	t_stack *a;      // Ana stack
	t_stack *b;      // Yardımcı stack
	t_opcount ops;   // Operasyon sayaçları
	double disorder; // Disorder metriği (0-1)
	int bench_f;     // --bench aktif mi? (1/0)
	char *strategy;  // Seçilen strateji ("simple", "adaptive" vb.)
						// Diğer: Argüman sayısı, vb.
} t_data;

// ft_adaptive
double	ft_compute_disorder(t_stack *a);

// ft_bench
void	ft_print_op_breakdown(const t_opcount *ops);
void	ft_print_bench(const t_data *d, int strategy, int resolved_s);

// ft_flags
int	ft_parse_flags(int argc, char **argv, int *forced_s, int *bench_f);
int	ft_first_number_index(int argc, char **argv);

// ft_index
void	ft_assign_index(t_stack *a);

// ft_operations
void	ft_pa(t_data *d);
void	ft_pb(t_data *d);

// ft_operations_reverse_rotate
void	ft_rra(t_data *d);
void	ft_rrb(t_data *d);
void	ft_rrr(t_data *d);

// ft_operations_rotate
void	ft_ra(t_data *d);
void	ft_rb(t_data *d);
void	ft_rr(t_data *d);

// ft_operations_swap
void	ft_sa(t_data *d);
void	ft_sb(t_data *d);
void	ft_ss(t_data *d);

// ft_parse_args
void	ft_parse_args(int argc, char **argv, t_stack *a, t_stack *b);

// ft_parse_atol
long	ft_atol(const char *str, t_stack *a, t_stack *b);

// ft_helpers
int	ft_count_arguments(char **args);
void	ft_free_split(char **str);
int	ft_allocate_stacks(t_stack *a, t_stack *b);
void	ft_error_exit(t_stack *a, t_stack *b);

// ft_sort_complex
void	ft_sort_complex(t_data *d);

// ft_sort_medium
void	ft_sort_medium(t_data *d);

// ft_sort_simple
void	ft_sort_simple(t_data *d);
void	ft_sort_three(t_data *d);
void	ft_sort_five(t_data *d);

// ft_stack_utils
int	ft_is_full(t_stack *stack);
int	ft_is_sorted(t_stack *stack);

// ft_stack_utils2
void	ft_shift_up(t_stack *stack);
void	ft_shift_down(t_stack *stack);
void	ft_print_op(char *op);
int	ft_can_swap(t_stack *stack);
int	ft_can_push(t_stack *stack);

// ft_strategy
int	ft_resolve_strategy(double disorder, int forced_strategy);
void	ft_run_strategy(t_data *d, int strategy);
const char	*ft_strategy_name(int strategy);
const char	*ft_strategy_complexity(int strategy);

// main
int	main(int argc, char **argv);

int ft_get_chunk_size(int size);
void ft_push_chunks(t_data *d, int chunk);
int ft_find_max_pos(t_stack *b);
int ft_get_max_bits(t_stack *a);
void ft_radix_pass(t_data *d, int bit);
int ft_swap(t_stack **stack);
int ft_get_min_value(t_stack *a);
void ft_bring_min_to_top(t_data *d, int min_pos);
int ft_get_min_pos_value(t_stack *a, int value);
int ft_parse_runtime_flags(int argc, char **argv, int *forced_s, int *bench_f);
int ft_init_and_parse(int argc, char **argv, t_stack *a, t_stack *b);
void ft_prepare_data(t_data *d, t_stack *a, t_stack *b, int bench_f);
void ft_cleanup(t_stack *a, t_stack *b);
int ft_select_adaptive_strategy(double disorder);
int ft_flag_to_strategy(const char *arg);
int ft_is_flag(const char *arg);
int ft_helper_parse_flag(const char *arg, int *forced_s, int *bench_f);
void ft_print_disorder(double disorder);
void ft_print_strategy_info(int strategy, int resolved_s);
void ft_print_op_line(const char *label, int value);
int ft_find_min_pos(t_stack *a);
void ft_push_min_to_b(t_data *d);
long ft_atol_helper(const char *str, long res, t_stack *a, t_stack *b);
int ft_sign_halper(char *str);
void ft_check_empty_args(char **argv, int argc, t_stack *a, t_stack *b);
char *ft_join_all_args(char **argv, int argc, t_stack *a, t_stack *b);
void ft_check_duplicates(t_stack *a, t_stack *b);
int ft_rotate(t_stack **stack);
int ft_reverse_rotate(t_stack **stack);
int ft_push(t_stack **from, t_stack **to);
void ft_init_index(int *idx, int size);
int ft_get_min_pos(t_stack *a, int *idx);


#endif
