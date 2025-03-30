/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:36:23 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/16 20:36:24 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst -> content);
		lst = lst -> next;
	}
}

/*void ft_iterate(void *content)
{
	int *new = (int *)content;
	(*new) *= 2;
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

	ft_lstiter(start, ft_iterate);

	printf("The new content of the list is:\n");
	ft_printlst(start);

	freelst(start);
}*/
