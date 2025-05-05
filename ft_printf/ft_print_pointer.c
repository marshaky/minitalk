/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_pointer_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:32:45 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/12 10:20:13 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args)
{
	unsigned long	ptr;
	int				count;
	char			*hex_str;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (write(1, "0x0", 3));
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	hex_str = ft_itoa_base(ptr, 16, "0123456789abcdef");
	if (!hex_str)
		return (-1);
	count += write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}
