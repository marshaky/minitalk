/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:07:58 by marshaky          #+#    #+#             */
/*   Updated: 2025/01/27 01:14:52 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;
	size_t		i;

	last = NULL;
	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (*str == (char)c)
			last = str;
		str++;
	}
	return ((char *)last);
}
