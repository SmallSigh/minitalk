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

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

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
		printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	message_length = 0;
	server_pid = atoi(av[1]);
	while (av[2][message_length])
		message_length++;
	printf("Sending length: %d\n", message_length);
	send_number(server_pid, message_length);
	printf("Sending message: %s\n", av[2]);
	send_message(server_pid, av[2]);
	return (0);
}
