/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:28:59 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/05/27 19:29:00 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_an_ber_extension(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_printf("Error\nThe given file is not an *.ber extension!!!!!\n");
		exit(0);
	}
}

int	check_map_components(char *line, t_checker *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E' || line[i] == 'P')
			map->exit_and_start += 1;
		if (line[i] == 'C')
			map->collectible += 1;
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P' && line[i] != '\n')
			map->valid_chars = 1;
		i++;
	}
	return (0);
}

void	is_surrounded(char *str, int size, t_checker *map)
{
	int			i;
	static int	signal = 0;

	i = 0;
	map->last_row = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[0] != '1' || str[size - 1] != '1')
		{
			map->surronded_by_walls = 1;
			validate_map(str, map);
		}
		if (str[i] != '1')
		{
			if (signal == 0)
			{
				map->first_row = 1;
				validate_map(str, map);
			}
			map->last_row = 1;
		}
		i++;
	}
	signal = 1;
}

void	is_rectangular(char *str, int size, t_checker *map)
{
	static int	signal = 0;
	static int	width = 0;

	if (signal == 0)
	{
		map->width = size;
		width = size;
		signal = 1;
	}
	else if (size != width)
	{
		map->is_rect = 1;
		validate_map(str, map);
	}
}
