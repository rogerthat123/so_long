/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:35:29 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/15 22:35:30 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

/*void freenode(t_list *lst)
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
			ft_lstadd_back(&start, new);
		}
	}
	printf("%d\n", *(int *)ft_lstlast(start) -> content);
        freenode(start);

}*/
