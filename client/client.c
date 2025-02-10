/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:49:45 by masmit            #+#    #+#             */
/*   Updated: 2025/02/10 18:39:01 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

void	send_bit(int server_pid, short bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	usleep(100);
}

void	send_message(int server_pid, char *message)
{
	int	i;
	int	bit;

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
	ft_printf("Message has been sent...\n");
}

// least significant bit first;
void	send_length(int server_pid, uint32_t message_length)
{
	int	bit;

	bit = 31;
	while (bit >= 0)
	{
		send_bit(server_pid, (message_length >> bit) & 1);
		bit--;
	}
	ft_printf("Message length has been sent...\n");
}

int	main(int argc, char **argv)
{
	__pid_t		server_pid;
	uint32_t	message_length;
	
	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <1 or 2>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message_length = 0;
	while (argv[2][message_length])
		message_length++;
	send_length(server_pid, message_length);
	send_message(server_pid, argv[2]);
	ft_printf("Signal sent to PID <%d>\n", server_pid);
	return (0);
}
