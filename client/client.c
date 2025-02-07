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

int main(int argc, char **argv)
{
	int	server_pid;
	int	signal_type;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <1 or 2>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal_type = ft_atoi(argv[2]);
	if (signal_type == 1)
		kill(server_pid, SIGUSR1);
	else if (signal_type == 2)
		kill(server_pid, SIGUSR2);
	else
	{
		ft_printf("Invalid signal type. Use 1 for SIGUSR1, 2 for SIGUSR2.\n");
		return (1);
	}
	ft_printf("Signal sent to PID <%d>\n", server_pid);
	return (0);
}
