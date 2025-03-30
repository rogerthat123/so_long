/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:13:15 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/12 23:13:16 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_checker	map_info;

	ft_memset(&map_info, 0, sizeof(t_checker));
	if (argc != 2)
	{
		ft_printf("Error\nNr. of arguments is not valid!\n");
		return (0);
	}
	map_check(argv[1], &map_info);
	game_init(&map_info);
	clean(&map_info);
	return (0);
}
