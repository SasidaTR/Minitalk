/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:34 by hrischma          #+#    #+#             */
/*   Updated: 2024/06/21 10:44:59 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_fgets(char *str, int n, int fd)
{
	int	i;
	int	bytes_read;

	i = 0;
	if (!str || n <= 0)
		return (NULL);
	while (i < n - 1)
	{
		bytes_read = read(fd, &str[i], 1);
		if (bytes_read <= 0)
		{
			if (i == 0)
				return (NULL);
			break ;
		}
		if (str[i] == '\n')
			break ;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("\033[1;32mReceived : %i\033[0m\n", received);
		received = 0;
	}
}

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	pid_t		target_pid;
	char		message[1024];

	if (argc != 3 || !ft_strlen(argv[2]) || ft_atoi(argv[1]) < 1)
		return (1);
	target_pid = ft_atoi(argv[1]);
	ft_printf("Sent : '%s' to %i\n", argv[2], target_pid);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(target_pid, argv[2]);
	while (1)
	{
		ft_printf("Enter message to send: ");
		if (!ft_fgets(message, sizeof(message), STDIN_FILENO))
			break ;
		message[ft_strlen(message)] = '\0';
		if (ft_strlen(message) == 0)
			continue ;
		ft_printf("Sent : '%s' to %i\n", message, target_pid);
		signal(SIGUSR1, action);
		signal(SIGUSR2, action);
		mt_kill(target_pid, message);
		usleep(120 * ft_strlen(message) + 100);
	}
	return (0);
}
