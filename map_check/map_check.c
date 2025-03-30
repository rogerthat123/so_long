/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:49:32 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/07 22:29:54 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_map(char *str, t_checker *map)
{
	if ((map->rows == map->width) || map->is_rect == 1)
		ft_printf("Error\nThe map must be rectangular!!\n");
	else if (map->first_row == 1 || map->surronded_by_walls == 1
		|| map->last_row == 1)
		ft_printf("Error\nThe map must be surrounded by walls!!\n");
	else if (map->collectible < 1)
		ft_printf("Error\nYou need at least one collectible!!\n");
	else if (map->exit_and_start != 2)
		ft_printf("Error\nThe map must have one start and one exit point\n");
	else if (map->valid_chars == 1)
		ft_printf("Error\nThe map contains forbidden characters!\n");
	else if (map->is_rect == 1)
		ft_printf("Error\nThe map must be rectangular!!\n");
	else if (!(store_map(map, NULL, 1)))
		ft_printf("Error\nThe map path is not valid!!!\n");
	else
		return ;
	free(str);
	get_next_line(-1);
	store_map(map, NULL, 2);
	exit(0);
}

void	check_map_conditions(char *str, int size, t_checker *map_checker)
{
	is_rectangular(str, size, map_checker);
	check_map_components(str, map_checker);
	is_surrounded(str, size, map_checker);
	map_checker->rows += 1;
}

void	map_check(char *map_path, t_checker *map_checker)
{
	char		*str;
	int			fd;
	int			size;

	is_an_ber_extension(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_message(1);
	str = get_next_line(fd);
	if (!str)
		error_message(2);
	while (str)
	{
		size = ft_strlen(str) - 1;
		check_map_conditions(str, size, map_checker);
		store_map(map_checker, str, 0);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	validate_map (str, map_checker);
}
