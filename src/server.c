/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:57:04 by fharing           #+#    #+#             */
/*   Updated: 2021/08/26 11:59:20 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_client_pid = 0;

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_to_binary(char c)
{
	static int	bits = 1;
	static int	character = 48;
	static int	flag = 1;

	character = character + c * bits;
	bits = bits * 2;
	if (bits == 256)
	{
		if (flag == 0)
			write (1, &character, 1);
		if (character == 12385)
			flag = 0;
		if (flag == 1)
			g_client_pid = g_client_pid * 10 + character - 12336;
		if (character == 12292)
		{
			flag = 1;
			usleep(100);
			kill(g_client_pid, SIGUSR2);
			g_client_pid = 0;
		}
		character = 48;
		bits = 1;
	}
}

void	sigfunc(int sig)
{
	if (sig == SIGUSR1)
		ft_to_binary('1');
	if (sig == SIGUSR2)
		ft_to_binary('0');
}

int	main(void)
{
	int	i;

	i = 0;
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, sigfunc);
		signal(SIGUSR2, sigfunc);
		pause();
		i++;
		if (i == 8)
			i = 0;
	}
	return (0);
}
