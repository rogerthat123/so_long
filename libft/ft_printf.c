/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:11:43 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/10/28 17:52:43 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(const char *format, va_list args, int *pos)
{
	(*pos)++;
	if (format[*pos] == 'c')
		ft_putchar_fd (va_arg(args, int), 1);
	else if (format[*pos] == 's')
		return (print_string(va_arg(args, char *)));
	else if (format[*pos] == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (format[*pos] == 'u')
		return (ft_unsig(va_arg(args, int)));
	else if (format[*pos] == 'x')
		return (ft_hexa(va_arg(args, int), 1));
	else if (format[*pos] == 'X')
		return (ft_hexa(va_arg(args, int), 2));
	else if (format[*pos] == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;	
	int		i;
	int		charcount;

	i = 0;
	charcount = 0;
	va_start (args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			charcount += check_format (format, args, &i);
		else
		{
			ft_putchar_fd (format[i], 1);
			charcount++;
		}
		i++;
	}
	va_end (args);
	return (charcount);
}

/*int main (void)
{
		int c = 2;
		int *ptr = &c;

		ft_printf("Hello Mr. %c. %s\n", 'X', "We have a mission for you!");
		ft_printf("My printf --------> %p\n", ptr);
		printf("Original printf --> %p\n", ptr);
		ft_printf("My printf --------> %d and %i\n", 1500, 600);
		printf("Original printf --> %d and %i\n", 1500, 600);
		ft_printf("My printf --------> %u\n", -25);
		printf("Original printf --> %u\n", -25); 
		ft_printf("%x\n", 25865284582);
		ft_printf("%X\n", 25865284582);
		ft_printf("%%\n");
		return (0);
}*/
