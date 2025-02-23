/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:18:10 by masmit            #+#    #+#             */
/*   Updated: 2025/02/19 17:18:10 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = negative * -1;
		if ((nptr[i] == '-' || nptr[i] == '+')
			&& (nptr[i + 1] == '-' || nptr[i + 1] == '+'))
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + negative * (nptr[i] - '0');
		i++;
	}
	return (result);
}

void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	usleep(500);
}

void	send_number(pid_t server_pid, int num)
{
	int	bit;

	bit = 31;
	while (bit >= 0)
	{
		send_bit(server_pid, (num >> bit) & 1);
		bit--;
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			send_bit(server_pid, (message[i] >> bit) & 1);
			bit--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	int		message_length;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	message_length = 0;
	server_pid = ft_atoi(av[1]);
	while (av[2][message_length])
		message_length++;
	ft_printf("Sending length: %d\n", message_length);
	send_number(server_pid, message_length);
	ft_printf("Sending message: %s\n", av[2]);
	send_message(server_pid, av[2]);
	return (0);
}
