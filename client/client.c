/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:49:45 by masmit            #+#    #+#             */
/*   Updated: 2025/02/07 20:42:38 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else if (bit == 0)
		kill(server_pid, SIGUSR2);
	usleep(100);
}

void	send_message(pid_t server_pid, char *message)
{
	uint32_t	i;
	int			bit;

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

void	send_number(pid_t server_pid, uint32_t length)
{
	int	bit;

	bit = 32;
	while (bit >= 0)
	{
		send_bit(server_pid, (length >> bit) & 1);
		bit--;
	}
}

int main(int argc, char **argv)
{
	pid_t			server_pid;
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
	ft_printf("Sending length...\n");
	send_number(server_pid, message_length);
	ft_printf("Sending message...\n");
	send_message(server_pid, argv[2]);
	return (0);
}
