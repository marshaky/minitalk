/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:26:44 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/14 03:44:02 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list args)
{
	int		val;
	char	*str;
	int		len;

	val = va_arg(args, int);
	str = ft_itoa(val);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
