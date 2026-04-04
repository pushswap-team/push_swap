/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 04:12:37 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/02/19 13:55:45 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0 && len != '\0')
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}
