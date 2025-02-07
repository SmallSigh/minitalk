/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printHex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:06:55 by masmit            #+#    #+#             */
/*   Updated: 2025/02/07 19:55:44 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper_print(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

size_t	ft_len_print(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_pointer(uintptr_t n)
{
	int		print_length;
	char	hex_buffer[32];
	int		i;

	i = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	print_length = write(1, "0x", 2);
	while (n > 0)
	{
		hex_buffer[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i > 0)
		print_length += ft_print_char(hex_buffer[--i]);
	return (print_length);
}

int	ft_print_hex(unsigned int n, char c)
{
	int					print_length;
	char				hex_buffer[32];
	int					i;

	i = 0;
	print_length = 0;
	if (n == 0)
		return (ft_print_char('0'));
	while (n > 0)
	{
		hex_buffer[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	n = i;
	while (0 < i-- && c == 'X')
		hex_buffer[i] = ft_toupper_print(hex_buffer[i]);
	i = n;
	while (i > 0)
		print_length += ft_print_char(hex_buffer[--i]);
	return (print_length);
}
