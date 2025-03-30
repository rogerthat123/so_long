/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:07:21 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/15 22:07:22 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstsize(lst -> next));
}

/*int main(int argc, char **argv)
{
	t_list *first = NULL;

	for (int i = 1; i < argc; i++)
	{
		t_list *new_node = ft_lstnew(argv[i]);
		if (!new_node)
			return (1);
		else
			ft_lstadd_front(&first, new_node);
	}

	printf("%d\n", ft_lstsize(first));
	while (first != NULL)
	{
		t_list *temp = first;
		first = first->next;
		free(temp);
	}

	return 0;
}*/
