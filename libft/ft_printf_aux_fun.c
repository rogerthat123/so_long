/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:06:19 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/28 17:27:23 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(void *ptr)
{
	char	hexa[20];
	char	*hexa_base;

	auto int i = 0;
	auto int count = 0;
	hexa_base = "0123456789abcdef";
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd ("0x", 1);
	while (ptr != NULL)
	{
		hexa[i] = hexa_base[(size_t)ptr % 16];
		ptr = (void *)((size_t)ptr / 16);
		i++;
	}
	count = i + 2;
	while (i > 0)
	{
		i--;
		ft_putchar_fd(hexa[i], 1);
	}
	return (count);
}

int	ft_hexa(unsigned int nbr, int signal)
{
	char	hexa[20];
	char	*hexa_base;

	auto int i = 0;
	auto int count = 0;
	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	if (signal == 1)
		hexa_base = "0123456789abcdef";
	else
		hexa_base = "0123456789ABCDEF";
	while (nbr > 0)
	{
		hexa[i] = hexa_base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	count = i;
	while (i-- > 0)
		ft_putchar_fd(hexa[i], 1);
	return (count);
}

int	ft_unsig(unsigned int nbr)
{
	static int	count;

	count = 0;
	if (nbr > 9)
		ft_unsig(nbr / 10);
	ft_putnbr_fd(nbr % 10, 1);
	count++;
	return (count);
}

int	print_string(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_nbr(int nbr)
{
	int		charcount;
	char	*str;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	charcount = (ft_strlen(str));
	free(str);
	return (charcount);
}
