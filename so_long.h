/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <rneto-fo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:16:29 by rneto-fo          #+#    #+#             */
/*   Updated: 2024/06/29 15:12:05 by rneto-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <unistd.h>

# define CELL_SIZE 32
# define BACK_XPM	"textures/back.xpm"
# define WALL_XPM	"textures/wall.xpm"
# define HERO_XPM	"textures/hero.xpm"
# define EXIT_XPM	"textures/exit.xpm"
# define EXIT_O_XPM "textures/open_exit.xpm"
# define COLLECT_XPM "textures/collect.xpm"

typedef struct s_map_checker
{
	char	**map;
	int		exit_and_start;
	int		collectible;
	int		valid_chars;
	int		first_row;
	int		surronded_by_walls;
	int		last_row;
	int		rows;
	int		width;
	int		is_rect;
	int		x;
	int		y;

}	t_checker;

typedef struct s_pos
{
	int	x;
	int	y;
	int	collect;
	int	exit;
}	t_pos;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*buffer;
	void		*img_back;
	void		*img_wall;
	void		*img_hero;
	void		*img_collect;
	void		*img_exit;
	void		*img_open_exit;
	char		*buffer_addr;
	int			width;
	int			height;
	int			x;
	int			y;
	int			bpp;
	int			line_length;
	int			endian;
	t_checker	*map_info;
}	t_game;

// utils

void	error_message(int signal);
void	free_map(t_checker *map_info, char **map);
void	clean(t_checker *map_info);
void	game_clear(t_game *game);
int		clean_game(t_game *game);

// map_check
void	map_check(char *map_path, t_checker *map_checker);
void	validate_map(char *str, t_checker *map);
void	is_an_ber_extension(char *map_path);
void	is_surrounded(char *str, int size, t_checker *map);
void	is_rectangular(char *str, int size, t_checker *map);
int		store_map(t_checker *s_map_checker, char*str, int signal);
int		check_map_components(char *line, t_checker *map);

//game

void	game_init(t_checker *map_info);
void	upload_image(t_checker *map_info, t_game *game);
void	*fish_image(t_game *game, char element);
int		move_main(int keycode, t_pos *game, t_checker *game_info);
int		move_hero(int keycode, t_game *game);

#endif