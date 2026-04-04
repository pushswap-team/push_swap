/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 02:49:04 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/02/19 13:55:57 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_array(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static char	**fill_array(char const *s, char c, char **array)
{
	int	i;
	int	word_len;
	int	word_index;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_len = 0;
			while (s[i + word_len] && s[i + word_len] != c)
				word_len++;
			array[word_index] = ft_substr(s, i, word_len);
			if (!array[word_index])
				return (free_array(array, word_index));
			word_index++;
			i += word_len;
		}
		else
			i++;
	}
	array[word_index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	return (fill_array(s, c, array));
}
