/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:54:22 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/14 01:31:52 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	str_to_bit(char *str, int p_id)
{
	int				i;
	int				a;
	unsigned char	n;

	a = 0;
	while (str[a])
	{
		n = str[a];
		i = 9;
		while (--i)
		{
			if ((n % 2) == 1)
			{
				kill(p_id, SIGUSR2);
				usleep(100);
			}
			if ((n % 2) == 0)
			{
				kill(p_id, SIGUSR1);
				usleep(100);
			}
			n = n / 2;
		}
		a++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) > 0)
			str_to_bit(av[2], ft_atoi(av[1]));
		else
		{	
			ft_printf("\nInvalid PID number\n");
		}
	}
	else
	{
		ft_printf("\nWRONG ARGUMENT\n");
	}
}