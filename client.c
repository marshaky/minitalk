/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:54:22 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/19 18:02:02 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_countbitreceived = 0;

int	ft_sendchar(int server_id, char letter)
{
	int		c;

	c = 0;
	while (c < 8)
	{
		if (g_countbitreceived != c)
			pause();
		if ((letter & (1 << c)))
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		c++;
	}
	return (0);
}

void	ft_handlesig(int signum)
{
	if (signum == SIGUSR2)
		g_countbitreceived += 1;
	if (g_countbitreceived > 7)
		g_countbitreceived = 0;
}

static int	validate_args(int argc, char **argv, int *server_id)
{
	if (argc != 3)
	{
		ft_putstr("Invalid arguments\n");
		return (-1);
	}
	if (ft_atoi(argv[1], server_id) == -1 || *server_id < 1
		|| kill(*server_id, 0) == -1)
	{
		ft_putstr("Invalid PID\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	server_id;
	int	i;

	i = 0;
	signal(SIGUSR1, ft_handlesig);
	signal(SIGUSR2, ft_handlesig);
	if (validate_args(argc, argv, &server_id) == -1)
		return (1);
	while (argv[2][i])
		ft_sendchar(server_id, argv[2][i++]);
	ft_sendchar(server_id, '\n');
	ft_putstr("Finished!\n");
	return (0);
}
