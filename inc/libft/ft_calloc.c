/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:59:38 by masmit            #+#    #+#             */
/*   Updated: 2025/02/07 19:47:22 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dont check either for zero, otherwise it wont pass paco
// memset dont work the same as bzero
// can check for max size aswell, but now its max int fot no overflow.
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;

	if ((nmemb * size) > 2147483647)
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (arr);
	ft_bzero(arr, size * nmemb);
	return (arr);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	size_t	calloc_size;
// 	void	*arr;

// 	if (nmemb == 0)
// 		return (0);
// 	calloc_size = nmemb * size;
// 	arr = malloc(sizeof(void) * calloc_size);
// 	if (arr != NULL)
// 		ft_memset(arr, 0, calloc_size);
// 	return (arr);
// }
