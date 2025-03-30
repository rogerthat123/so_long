/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:13:04 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/16 20:13:05 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*start;

	if (lst == NULL || del == NULL)
		return ;
	start = *lst;
	while (start != NULL)
	{
		temp = start->next;
		del(start-> content);
		free(start);
		start = temp;
	}
	*lst = NULL;
}
