/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:07:21 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/29 15:14:34 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_image(t_game *game)
{
	game->img_back = mlx_xpm_file_to_image(game->mlx, BACK_XPM,
			&game->width, &game->height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_XPM,
			&game->width, &game->height);
	game->img_hero = mlx_xpm_file_to_image(game->mlx, HERO_XPM,
			&game->width, &game->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_XPM,
			&game->width, &game->height);
	game->img_open_exit = mlx_xpm_file_to_image(game->mlx, EXIT_O_XPM,
			&game->width, &game->height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, COLLECT_XPM,
			&game->width, &game->height);
	game->buffer = mlx_new_image(game->mlx, game->map_info->width * CELL_SIZE,
			game->map_info->rows * CELL_SIZE);
}

void	draw_to_buffer(t_game *game, void *img, int x, int y)
{
	int		i;
	char	*img_addr;
	char	*buffer_addr;

	img_addr = mlx_get_data_addr(img, &game->bpp, &game->line_length,
			&game->endian);
	buffer_addr = mlx_get_data_addr(game->buffer, &game->bpp,
			&game->line_length, &game->endian)
		+ ((y * game->line_length) + (x * (game->bpp / 8)));
	i = 0;
	if (x < 0 || y < 0 || x >= game->map_info->width * CELL_SIZE
		|| y >= game->map_info->rows * CELL_SIZE)
	{
		ft_printf("Error: x or y is out of bounds\n");
		return ;
	}
	while (i < CELL_SIZE)
	{
		ft_memcpy(buffer_addr + (i * game->line_length), img_addr
			+ (i * CELL_SIZE * (game->bpp / 8)), CELL_SIZE * (game->bpp / 8));
		i++;
	}
}

void	upload_hero(t_checker *map_info, t_game *game)
{
	static int	collect = 0;
	int			hero_x;
	int			hero_y;

	hero_x = map_info->x / CELL_SIZE;
	hero_y = map_info->y / CELL_SIZE;
	if (map_info->map[hero_y][hero_x] == 'C')
	{
		map_info->map[hero_y][hero_x] = '0';
		collect++;
	}
	if (map_info->map[hero_y][hero_x] == 'E')
	{
		if (collect == map_info->collectible)
		{
			draw_to_buffer(game, game->img_open_exit, map_info->x, map_info->y);
			mlx_put_image_to_window (game->mlx, game->win, game->buffer, 0, 0);
			mlx_do_sync(game->mlx);
			usleep(20000);
			clean_game(game);
		}
	}
	draw_to_buffer(game, game->img_hero, map_info->x, map_info->y);
}

void	upload_image(t_checker *map_info, t_game *game)
{
	int		i;
	int		j;
	char	element;
	void	*image;

	i = 0;
	while (i < map_info->rows)
	{
		j = 0;
		while (j < map_info->width)
		{
			element = map_info->map[i][j];
			image = fish_image(game, element);
			if (image)
				draw_to_buffer(game, image,
					j * CELL_SIZE, i * CELL_SIZE);
			j++;
		}
		i++;
	}
	upload_hero(map_info, game);
	mlx_put_image_to_window (game->mlx, game->win, game->buffer, 0, 0);
}

void	game_init(t_checker *map_info)
{
	t_game	game;

	map_info->x *= CELL_SIZE;
	map_info->y *= CELL_SIZE;
	game.map_info = map_info;
	game.mlx = mlx_init();
	if (!game.mlx)
		error_message(4);
	game.win = mlx_new_window(game.mlx, map_info->width * CELL_SIZE,
			map_info->rows * CELL_SIZE, "SO_LONG!");
	if (!game.win)
		error_message(5);
	get_image(&game);
	upload_image(map_info, &game);
	mlx_key_hook(game.win, move_hero, &game);
	mlx_hook(game.win, 17, 1L << 0, clean_game, &game);
	mlx_loop(game.mlx);
}
