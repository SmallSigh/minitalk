/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:07:18 by masmit            #+#    #+#             */
/*   Updated: 2025/02/23 16:10:21 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_message_length(t_server *server_info, int received_bit)
{
	server_info->message_length |= (received_bit << (31 - server_info->bit));
	server_info->bit++;
	if (server_info->bit == 32)
	{
		ft_printf("Received message length: %d\n", server_info->message_length);
		server_info->message = malloc(server_info->message_length + 1);
		if (!server_info->message)
		{
			ft_printf("Memory allocation failed.\n");
			exit(1);
		}
		server_info->message[server_info->message_length] = '\0';
		server_info->char_index = 0;
		server_info->receiving_length = 0;
		server_info->bit = 0;
	}
}

void	handle_message_data(t_server *server_info, int received_bit)
{
	server_info->cur_char |= (received_bit << (7 - server_info->bit));
	server_info->bit++;
	if (server_info->bit == 8)
	{
		server_info->message[server_info->char_index] = server_info->cur_char;
		server_info->char_index++;
		server_info->bit = 0;
		server_info->cur_char = 0;
		if (server_info->char_index == server_info->message_length)
		{
			ft_printf("%s\n", server_info->message);
			if (server_info->message)
			{
				free(server_info->message);
				server_info->message = NULL;
			}
			server_info->message_length = 0;
			server_info->char_index = 0;
			server_info->bit = 0;
			server_info->cur_char = 0;
			server_info->receiving_length = 1;
		}
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	int				received_bit;
	static t_server	server_info = {0, 0, 1, NULL, 0, 0};

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		received_bit = 1;
	else
		received_bit = 0;
	if (server_info.receiving_length)
		handle_message_length(&server_info, received_bit);
	else
		handle_message_data(&server_info, received_bit);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID = <%d>\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
