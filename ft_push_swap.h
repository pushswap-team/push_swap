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
# define LLONG_MAX 9223372036854775807LL

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
void	ft_print_bench(const t_data *d, int strategy);

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

#endif
