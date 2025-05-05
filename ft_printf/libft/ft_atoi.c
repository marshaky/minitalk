/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:51 by marshaky          #+#    #+#             */
/*   Updated: 2025/01/24 03:28:39 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' \
			|| c == '\f' || c == '\n')
		return (1);
	return (0);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	num;

	i = 0;
	while (is_space(str[i]))
		++i;
	res = 1;
	if (!is_digit(str[i]))
	{
		if (str[i] == '-')
			res = -1;
		else if (str[i] != '+')
			return (0);
		i++;
	}
	num = 0;
	while (is_digit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (res * num);
}
