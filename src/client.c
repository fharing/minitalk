/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:56:57 by fharing           #+#    #+#             */
/*   Updated: 2021/08/26 11:57:33 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_check_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_error_handling(int argc, char **argv)
{
	if (argc != 3 || argv[2] == 0)
	{
		write(1, "Wrong input!", 12);
		exit (1);
	}
	if (ft_check_number(argv[1]) == 0)
	{
		write(1, "PID must be a number!", 21);
		exit (1);
	}
}

void	ft_char_to_binary(int pid, char a)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((a & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((a & 1) == 0)
			kill(pid, SIGUSR2);
		a = a >> 1;
		bits++;
		usleep(30);
	}
}

void	sigfunc(int sig)
{
	if (sig == SIGUSR2)
	{
		write (1, "CLIENT CLOSED\n", 15);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*pid_client;
	int		i;

	i = 0;
	ft_error_handling(argc, argv);
	pid = ft_atoi(argv[1]);
	pid_client = ft_itoa(getpid());
	while (pid_client[i] != 0)
		ft_char_to_binary(pid, pid_client[i++]);
	i = 0;
	ft_char_to_binary(pid, 'a');
	while (argv[2][i] != 0)
	{
		ft_char_to_binary(pid, argv[2][i]);
		i++;
	}
	ft_char_to_binary(pid, 4);
	while (1)
	{
		signal(SIGUSR2, sigfunc);
		pause();
	}
	return (0);
}
