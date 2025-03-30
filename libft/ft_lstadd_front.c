/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:14:37 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/15 19:14:38 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

/*void *printlst(t_list *lst)
{
	while(lst != NULL)
	{
		printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

void freenode(t_list *lst)
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


int main (void)
{
	t_list	*start;
	int	nodes;

	printf("Write how many nodes do you want: ");
	scanf("%d", &nodes);

	int	data[nodes];

	printf("Write the number that you want on the nodes: ");
	for(int i =0; i < nodes; i++)
		scanf("%d", &data[i]);

	for(int j = 0; j < nodes; j++)
	{
		t_list	*new;
		if (j == 0)
			start = ft_lstnew(&data[j]);
		else
		{
			new = ft_lstnew(&data[j]);
			ft_lstadd_front(&start, new);
		}
	}
	printlst(start);
        freenode(start);

}*/
