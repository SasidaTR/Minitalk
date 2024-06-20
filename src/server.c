/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:42 by hrischma          #+#    #+#             */
/*   Updated: 2024/06/20 11:52:39 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define _XOPEN_SOURCE 700
#include "../include/minitalk.h"

static void	reset_buffer(char *buffer, int *buf_index)
{
	buffer[*buf_index] = '\0';
	*buf_index = 0;
}

static void	handle_signal_end(pid_t *client_pid, char *buffer, int *buf_index)
{
	reset_buffer(buffer, buf_index);
	kill(*client_pid, SIGUSR2);
	*client_pid = 0;
	ft_printf("%s\033[1;32m\nMessage received successfully!\033[0m\n", buffer);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;
	static char				buffer[1024];
	static int				buf_index = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			handle_signal_end(&client_pid, buffer, &buf_index);
			return ;
		}
		buffer[buf_index++] = c;
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
