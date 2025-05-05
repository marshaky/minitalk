/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:07:03 by marshaky          #+#    #+#             */
/*   Updated: 2025/02/14 03:51:30 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *prm, ...);
int		ft_is_argument(int c);
int		ft_formats(va_list args, char specifier);
int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
int		ft_print_decimal(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_unsigned_decimal(va_list args);
int		ft_print_hex(va_list args, int uppercase);
int		ft_print_percent(void);
int		ft_putchar(char c);
char	*ft_itoa_base(unsigned long num, int base_len, char *base);

#endif