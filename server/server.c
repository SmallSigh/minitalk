/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:27:00 by masmit            #+#    #+#             */
/*   Updated: 2025/02/07 20:30:39 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

void signal_handeler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Received SIGUSR1.\n");
	if (signum == SIGUSR2)
		ft_printf("Received SIGUSR2.\n");
}

int main(void)
{
	ft_printf("Server PID = %d\n", getpid());
	
	signal(SIGUSR1, signal_handeler);
	signal(SIGUSR2, signal_handeler);

	while(1)
		pause();
}
