/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:21:23 by masmit            #+#    #+#             */
/*   Updated: 2024/11/02 16:32:35 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// iterate through list, save lst next under temp
// delete node and content, make tmp the new node to check
// no need to check if (lst is null,) that happens in the while loop
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
