/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:10:42 by masmit            #+#    #+#             */
/*   Updated: 2025/02/19 17:13:51 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_server
{
	int			bit;
	uint32_t	message_length;
	uint32_t	receiving_length;
	char		*message;
	size_t		char_index;
	char		cur_char;
}				t_server;

void	handle_message_length(t_server *server_info, int received_bit);
void	handle_message_data(t_server *server_info, int received_bit);
void	signal_handler(int signum, siginfo_t *info, void *context);

#endif