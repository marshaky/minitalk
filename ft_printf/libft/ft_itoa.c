/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:39:25 by marshaky          #+#    #+#             */
/*   Updated: 2025/01/24 01:49:42 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_cntr(int n)
{
	int	i;

	i = 0;
	if (n > -1 && i < 10)
		i++;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	check_num(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		i += digit_cntr(-n);
	}
	else
		i = digit_cntr(n);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = check_num(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
