/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:16:01 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/29 15:17:34 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_moves(void)
{
	static int	move = 1;

	ft_printf("Move nr: %d\n", move++);
}

int	move_hero(int keycode, t_game *game)
{
	int		hero_x;
	int		hero_y;
	bool	move;

	hero_x = game->map_info->x / CELL_SIZE;
	hero_y = game->map_info->y / CELL_SIZE;
	move = true;
	if (keycode == XK_a && game->map_info->map[hero_y][hero_x - 1] != '1')
		game->map_info->x -= CELL_SIZE;
	else if (keycode == XK_d && game->map_info->map[hero_y][hero_x + 1] != '1')
		game->map_info->x += CELL_SIZE;
	else if (keycode == XK_w && game->map_info->map[hero_y - 1][hero_x] != '1')
		game->map_info->y -= CELL_SIZE;
	else if (keycode == XK_s && game->map_info->map[hero_y + 1][hero_x] != '1')
		game->map_info->y += CELL_SIZE;
	else if (keycode == XK_Escape)
		clean_game(game);
	else
		move = false;
	if (move)
		print_moves();
	mlx_clear_window(game->mlx, game->win);
	upload_image(game->map_info, game);
	return (0);
}

void	*fish_image(t_game *game, char element)
{
	if (element == '1')
		return (game->img_wall);
	if (element == '0' || element == 'P')
		return (game->img_back);
	if (element == 'C')
		return (game->img_collect);
	if (element == 'E')
		return (game->img_exit);
	return (NULL);
}
