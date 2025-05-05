/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:53:51 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/05 03:56:07 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

// client.c
void	send_char(pid_t pid, unsigned char c);

// server.c
void	handle_signal(int sig, siginfo_t *info, void *context);

#endif
