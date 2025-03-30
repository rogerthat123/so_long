/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:21:06 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/12 23:29:32 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_starting_point(t_checker *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->x = x;
				map->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	copy_map(char **dst, char **src, t_checker *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
}

void	check_path(char **map, t_pos *pos, t_checker *map_info, int signal)
{
	static int	exit = 0;
	static int	collect = 0;

	if (signal == 0)
	{
		pos->x = map_info->x;
		pos->y = map_info->y;
	}
	if (pos->x < 0 || pos->x >= map_info->width || pos->y < 0
		|| pos->y >= map_info->rows || map[pos->y][pos->x] == '1'
		|| map[pos->y][pos->x] == 'V')
		return ;
	else if (map[pos->y][pos->x] == 'E')
		exit = 1;
	else if (map[pos->y][pos->x] == 'C')
		collect++;
	map[pos->y][pos->x] = 'V';
	check_path(map, &(t_pos){pos->x + 1, pos->y, pos->collect = collect,
		pos->exit = exit}, map_info, 1);
	check_path(map, &(t_pos){pos->x - 1, pos->y, pos->collect = collect,
		pos->exit = exit}, map_info, 1);
	check_path(map, &(t_pos){pos->x, pos->y + 1, pos->collect = collect,
		pos->exit = exit}, map_info, 1);
	check_path(map, &(t_pos){pos->x, pos->y - 1, pos->collect = collect,
		pos->exit = exit}, map_info, 1);
}

int	get_path(t_checker *map_checker)
{
	t_pos	current;
	char	**map_mirrow;

	map_mirrow = malloc(sizeof(char *) * map_checker->rows);
	copy_map(map_mirrow, map_checker->map, map_checker);
	ft_memset(&current, 0, sizeof(current));
	find_starting_point(map_checker);
	check_path(map_mirrow, &current, map_checker, 0);
	free_map(map_checker, map_mirrow);
	if ((current.collect == map_checker->collectible) && (current.exit == 1))
		return (1);
	return (0);
}

int	store_map(t_checker *map_checker, char*str, int signal)
{
	char	**map;
	int		rows;

	if (str)
	{
		rows = map_checker->rows - 1;
		map = realloc(map_checker->map, sizeof(char *) * (rows + 1));
		if (!map)
			error_message(3);
		map_checker->map = map;
		map[rows] = malloc(sizeof(char) * map_checker->width + 2);
		if (!map[rows])
			error_message(3);
		ft_strlcpy(map[rows], str, map_checker->width + 2);
	}
	if (signal == 1)
		if (!get_path(map_checker))
			return (0);
	if (signal == 2)
		free_map (map_checker, map_checker->map);
	return (1);
}
