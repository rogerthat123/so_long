/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:44:59 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/05/23 15:43:31 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = (char *)malloc(size * sizeof(char));
	if (!final)
		return (NULL);
	while (s1 && *s1)
	{
		final[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		final[i++] = *s2;
		s2++;
	}
	final[i] = '\0';
	return (final);
}

/*int main(void)
{
    char str1[] = "Hello, ";
    char str2[] = "World!";
    char *fw;

    fw = ft_strjoin(str1, str2);

    if (fw == NULL)
        printf("Faillure\n");
    else
    {
        printf("%s\n", fw);
        free(fw);
    }
}*/
