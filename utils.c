/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:38:53 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/04/04 16:24:35 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_exit(t_stacks *stacks)
{
    if (stacks)
    {
        if (stacks->a)
            free(stacks->a);
        if (stacks->b)
            free(stacks->b);
    }
    write(2, "Error\n", 6); // stderr'e basıyoruz
    exit(1);
}
