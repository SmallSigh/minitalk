// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   server.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/07 20:27:00 by masmit            #+#    #+#             */
// /*   Updated: 2025/02/10 19:58:15 by masmit           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf.h"
// #include "libft.h"
// #include "minitalk.h"

// // m_d = message data;
// void handle_message_data(t_message_info *m_d, int received_bit)
// {
// 	m_d->current_char |= (received_bit << (7 - m_d->bit));
// 	m_d->bit++;
// 	if (m_d->bit == 8)
// 	{
// 		m_d->message[m_d->char_index] = m_d->current_char;
// 		ft_printf("%c", m_d->current_char);
// 		m_d->char_index++;
// 		m_d->bit = 0;
// 		m_d->current_char = 0;
// 		if (m_d->char_index == m_d->message_length)
// 		{
// 			ft_printf("Message has been received: %s\n", m_d->message);
// 			free(m_d->message);
// 			m_d->message = NULL;
// 			m_d->message_length = 0;
// 			m_d->char_index = 0;
// 			m_d->bit = 0;
// 			m_d->current_char = 0;
// 			m_d->receiving_length = 1;
// 		}
// 	}
// }

// void handle_message_length(t_message_info *message_data, int received_bit)
// {
// 	message_data->message_length |= (received_bit << (31 - message_data->bit));
// 	message_data->bit++;
// 	if (message_data->bit == 32)
// 	{
// 		message_data->message = malloc(message_data->message_length + 1);
// 		if (!message_data->message)
// 		{
// 			ft_printf("Something went wrong receiving the message, please try again.\n");
// 			exit(1);
// 		}
// 		ft_printf("Message length received! Making room for a message of size %d.\n", message_data->message_length);
// 		message_data->message[message_data->message_length] = '\0';
// 		message_data->receiving_length = 0;
// 		message_data->bit = 0;
// 	}
// }

// void signal_handler(int signum, siginfo_t *info, void *context)
// {
// 	static	t_message_info message_data = {NULL, 0, 0, 0, 1, 0};
// 	int		received_bit;

// 	(void)info;
// 	(void)context;
// 	received_bit = (signum == SIGUSR1) ? 1 : 0;
// 	if (message_data.receiving_length)
// 		handle_message_length(&message_data, received_bit);
// 	else
// 		handle_message_data(&message_data, received_bit);
// }

// int main(void)
// {
// 	struct sigaction	sa;
// 	pid_t				pid;

// 	pid = getpid();
// 	ft_printf("Server PID = <%d>\n", pid);
// 	sa.sa_flags = SA_SIGINFO;
// 	sa.sa_sigaction = signal_handler;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);

// 	while (1)
// 		pause();
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:27:00 by masmit            #+#    #+#             */
/*   Updated: 2025/02/10 18:49:32 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

// m_d = message data;
void handle_message_data(t_message_info *m_d, int received_bit)
{
	m_d->current_char |= (received_bit << (7 - m_d->bit));
	m_d->bit++;
	if (m_d->bit == 8)
	{
		m_d->message[m_d->char_index] = m_d->current_char;
		ft_printf("%c", m_d->current_char);
		m_d->char_index++;
		m_d->bit = 0;
		m_d->current_char = 0;
		if (m_d->char_index == m_d->message_length)
		{
			ft_printf("Message has been received: %s\n", m_d->message);
			free(m_d->message);
			m_d->message = NULL;
			m_d->message_length = 0;
			m_d->char_index = 0;
			m_d->bit = 0;
			m_d->current_char = 0;
			m_d->receiving_length = 1;
		}
	}
}

void handle_message_length(t_message_info *message_data, int received_bit)
{
	message_data->message_length |= (received_bit << (31 - message_data->bit));
	message_data->bit++;
	if (message_data->bit == 32)
	{
		message_data->message = malloc(message_data->message_length + 1);
		if (!message_data->message)
		{
			ft_printf("Something went wrong receiving the message, please try again.\n");
			exit(1);
		}
		ft_printf("Message length received! Making room for a message of size %d.\n", message_data->message_length);
		message_data->message[message_data->message_length] = '\0';
		message_data->receiving_length = 0;
		message_data->bit = 0;
	}
}

void signal_handler(int signum, siginfo_t *info, void *context)
{
	static	t_message_info message_data = {NULL, 0, 0, 0, 1, 0};
	int		received_bit;

	(void)info;
	(void)context;
	received_bit = (signum == SIGUSR1) ? 1 : 0;
	if (message_data.receiving_length)
		handle_message_length(&message_data, received_bit);
	else
		handle_message_data(&message_data, received_bit);
}

int main(void)
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
