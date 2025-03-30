/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:22:30 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/15 12:15:50 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (malloc(sizeof(t_list)));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

/*void freelst(t_list *lst)
{
	t_list	*temp;

	while(lst != NULL)
	{
		temp = lst-> next;
		free(lst);
		lst = temp;
	}
	free(lst);
}

void	*ft_printlst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", *(int*)lst-> content);
		lst = lst-> next;
	}
}

int main (void)
{
	t_list	*start;
	int	nodes;

	printf("Write how many nodes do you want: ");
	scanf("%d", &nodes);

	int	data[nodes];

	printf("write an value for each node: ");

	for (int j = 0; j < nodes; j++)
		scanf("%d", &data[j]);

	for(int i = 0; i < nodes; i++)
	{
		t_list	*new;
		if (i == 0)
			start = ft_lstnew(&data[i]);
		else
		{
			new = ft_lstnew(&data[i]);
			ft_lstadd_back(&start, new);
		}

	}
	printf("The content of your list is:\n");
	ft_printlst(start);
	freelst(start);
}*/
