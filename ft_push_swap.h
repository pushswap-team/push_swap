/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdayakli <bdayakli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:08:02 by bdayakli          #+#    #+#             */
/*   Updated: 2026/03/30 17:08:02 by bdayakli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int *array;      // Dinamik array, sayıları tutar
	int size;        // Şu an kaç eleman var (top index = size-1)
	int capacity;    // Maksimum kapasite (realloc için)
}

t_stack;

typedef struct s_opcount
{
	int sa, sb, ss;    // Swap'ler
	int pa, pb;        // Push'lar
	int ra, rb, rr;    // Rotate'ler
	int rra, rrb, rrr; // Reverse rotate'ler
	int total;         // Toplam operasyon
}

t_opcount;

typedef struct s_data
{
	t_stack *a;           // Ana stack
	t_stack *b;           // Yardımcı stack
	t_opcount ops;        // Operasyon sayaçları
	double disorder;      // Disorder metriği (0-1)
	int bench_flag;       // --bench aktif mi? (1/0)
	char *strategy;       // Seçilen strateji ("simple", "adaptive" vb.)
	// Diğer: Argüman sayısı, vb.
}

t_data;

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

# endif
