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
/*   Created: 2026/04/15 16:30:23 by bayseven          #+#    #+#             */
/*   Updated: 2026/04/15 16:30:23 by bayseven         ###   ########.fr       */
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

int	ft_swap(t_stack **stack);
int	ft_is_full(t_stack *stack);
int	ft_can_swap(t_stack *stack);
int	ft_can_push(t_stack *stack);
int	ft_is_empty(t_stack *stack);
int	ft_init_stack(t_stack *stack, int capacity);
int	ft_push(t_stack **from, t_stack **to);
int	ft_is_sorted(t_stack *stack);
int	ft_rotate(t_stack **stack);
int	ft_reverse_rotate(t_stack **stack);
int	ft_find_min_pos(t_stack *a);
int	ft_get_max_bits(t_stack *a);
int	ft_get_chunk_size(int size);
int	ft_count_arguments(char **args);
int	ft_allocate_stacks(t_stack *a, t_stack *b);
int	ft_select_adaptive_strategy(double disorder);
int	ft_resolve_strategy(double disorder, int forced_strategy);
int	ft_flag_to_strategy(const char *arg);
int	ft_parse_flags(int argc, char **argv, int *forced_s, int *bench_f);
int	ft_first_number_index(int argc, char **argv);
void	ft_assign_index(t_stack *a);
void	ft_sort_medium(t_data *d);
void	ft_run_strategy(t_data *d, int strategy);
void	ft_print_bench(const t_data *d, int strategy);
void	ft_print_op_breakdown(const t_opcount *ops);
void	ft_print_strategy_info(int strategy);
void	ft_print_disorder(double disorder);
void	ft_sort_complex(t_data *d);
void	ft_radix_pass(t_data *d, int bit);
void	ft_sort_simple(t_data *d);
void	ft_push_min_to_b(t_data *d);
void	ft_error_exit(t_stack *a, t_stack *b);
void	ft_parse_args(int argc, char **argv, t_stack *a, t_stack *b);
void	ft_check_duplicates(t_stack *a, t_stack *b);
void	ft_sa(t_data *d);
void	ft_sb(t_data *d);
void	ft_ss(t_data *d);
void	ft_pa(t_data *d);
void	ft_pb(t_data *d);
void	ft_free_stack(t_stack **stack);
void	ft_shift_up(t_stack *stack);
void	ft_shift_down(t_stack *stack);
void	ft_print_op(char *op);
void	ft_rra(t_data *d);
void	ft_rrb(t_data *d);
void	ft_rrr(t_data *d);
void	ft_ra(t_data *d);
void	ft_rb(t_data *d);
void	ft_rr(t_data *d);
char	**ft_split(char const *s, char c);
char	**ft_get_args_source(char **argv, int argc);
long	ft_atol(const char *str, t_stack *a, t_stack *b);
double	ft_compute_disorder(t_stack *a);
const char	*ft_strategy_name(int strategy);
const char	*ft_strategy_complexity(int strategy);
int	ft_atol_helper(const char *str, int res, t_stack *a, t_stack *b);

#endif


// kullNILn fonskiyonlar olsun sadece , 