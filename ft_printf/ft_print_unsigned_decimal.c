/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:36:01 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/12 10:19:18 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list args)
{
	unsigned int	val;
	int				len;
	char			*str;

	val = va_arg(args, unsigned int);
	str = ft_itoa_base(val, 10, "0123456789");
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
