/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:54:22 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/05 04:05:10 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: invalid PID\n");
		return (1);
	}
	str = argv[2];
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
	return (0);
}
