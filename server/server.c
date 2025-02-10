/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:27:00 by masmit            #+#    #+#             */
/*   Updated: 2025/02/10 16:47:53 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

int main(void)
{
	struct sigaction	sa;
	__pid_t				pid;

	pid = getpid();
	ft_printf("Server PID = <%d>\n", pid);
	sa.sa_flags = SA.SIGNINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask)
}
