/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:40:09 by marshaky          #+#    #+#             */
/*   Updated: 2025/01/24 01:51:10 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, size_t j)
{
	while (j)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j++;
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			j--;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	**fill_str(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				j++;
				s++;
			}
			str[i] = ft_substr(s - j, 0, j);
			if (str[i] == NULL)
				return (ft_free(str, i));
			i++;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	str = fill_str(str, s, c);
	return (str);
}
