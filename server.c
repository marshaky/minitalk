/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:53:25 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/14 01:29:40 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_signal(int signal)
{
	static int	count = 1;
	static int	c;
	static int	i = 0;

	if (signal == SIGUSR2)
	{
		c = c + count;
		count *= 2;
		i++;
	}
	if (signal == SIGUSR1)
	{
		count *= 2;
		i++;
	}
	if (i >= 8)
	{
		write(1, &c, 1);
		c = 0;
		count = 1;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_putnbr_fd(getpid(), 1);
	signal(SIGUSR2, check_signal);
	signal(SIGUSR1, check_signal);
	write(1, "\n", 1);
	while (1)
		pause();
}