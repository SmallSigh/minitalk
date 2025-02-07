/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:53:56 by masmit            #+#    #+#             */
/*   Updated: 2024/11/02 16:49:38 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

// small atoi
// added a failsafe for when (int n == INT_MIN)
static unsigned int	make_positive(int n)
{
	if (n < 0)
		return ((long int)n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long int	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = make_positive((long int)n);
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}
