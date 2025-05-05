/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:11:17 by marshaky          #+#    #+#             */
/*   Updated: 2025/01/24 03:06:42 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;

	arr = (void *)malloc(count * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}
