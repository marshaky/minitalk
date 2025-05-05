/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:36:36 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/12 10:18:04 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list args, int uppercase)
{
	unsigned int	val;
	char			*hex_str;
	int				count;
	char			*base;

	val = va_arg(args, unsigned int);
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	hex_str = ft_itoa_base(val, 16, base);
	if (!hex_str)
		return (-1);
	count = write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}
