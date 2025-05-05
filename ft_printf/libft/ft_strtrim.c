/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:40:20 by marshaky          #+#    #+#             */
/*   Updated: 2025/01/24 01:54:05 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && j > i && ft_strchr(set, s1[j - 1]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, j - i + 1);
	return (str);
}
