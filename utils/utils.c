/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:36:58 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/29 12:39:59 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_message(int signal)
{
	if (signal == 1)
		ft_printf("Error\nFailed to open the given file!!\n");
	else if (signal == 2)
		ft_printf("Error\nFailed to read the map!!\n");
	else if (signal == 3)
		ft_printf("Error\nFailed to allocate memory!!\n");
	else if (signal == 4)
		ft_printf("Error\nFailed to allocate mlx pointer\n!!");
	else if (signal == 5)
		ft_printf("Error\nFailed to allocate window pointer!!\n");
	exit(0);
}

void	game_clear(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_back);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_open_exit);
	mlx_destroy_image(game->mlx, game->img_hero);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	clean(t_checker *map)
{
	get_next_line(-1);
	store_map(map, NULL, 2);
	return ;
}

void	free_map(t_checker *map_info, char **map)
{
	int	i;

	i = 0;
	if (map_info && map_info->map)
	{
		while (i < map_info->rows)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	clean_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_back);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_open_exit);
	mlx_destroy_image(game->mlx, game->img_hero);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->buffer);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map_info, game->map_info->map);
	exit(0);
}
