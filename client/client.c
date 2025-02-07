/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:49:45 by masmit            #+#    #+#             */
/*   Updated: 2025/02/07 20:02:53 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

void signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Signal received!\n");
}

int main(void)
{
	// int pid;
	ft_printf("client PID = %d", getpid());
	return (0);
}
