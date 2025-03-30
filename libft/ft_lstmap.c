/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:02:54 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/18 19:02:56 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	start = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew ((*f)(lst->content));
		if (!new)
		{
			ft_lstclear (&start, del);
		}
		ft_lstadd_back (&start, new);
		lst = lst->next;
		new = new->next;
	}
	return (start);
}

/*void ft_delete(void *content)
{
	free(content);
}

void *ft_iterate(void *content)
{
	int *new = (int *)content;
	(*new) *= 2;
	return (new);

}

void	*ft_printlst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", *(int*)lst-> content);
		lst = lst-> next;
	}
}

void freelst(t_list *lst)
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
	t_list	*sec;
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

	sec = ft_lstmap(start, ft_iterate, ft_delete);
	
	printf("The content of the new list is:\n");
	ft_printlst(sec);

	freelst(start);
	freelst(sec);
}*/
