/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:52 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/24 15:57:31 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_sigusr(int signum, siginfo_t *info, void *ptr)
{
	static unsigned int	c = 0;
	static int			i = 0;

	(void)ptr;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar('\n');
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			ft_putchar(c);
			kill(info->si_pid, SIGUSR2);
		}
		c = 0;
		i = 0;
	}
	else
		kill(info->si_pid, SIGUSR2);
}

void	ft_server(void)
{
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void) argv;
	sa.sa_sigaction = &ft_handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_putstr("Invalid arguments\n");
		return (0);
	}
	ft_server();
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
