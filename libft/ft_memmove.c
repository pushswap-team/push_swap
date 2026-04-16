/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:33:19 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/02/19 13:55:42 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*srrc;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		dest = (unsigned char *)dst;
		srrc = (const unsigned char *)src;
		while (n > 0)
		{
			n--;
			dest[n] = srrc[n];
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
