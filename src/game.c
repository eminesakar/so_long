/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:25:08 by emsakar           #+#    #+#             */
/*   Updated: 2023/10/09 17:54:33 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	load_sprite(t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	game->dipper_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/hero.xpm", &tmp_x, &tmp_y);
	game->wall_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/wall.xpm", &tmp_x, &tmp_y);
	game->floor_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/floor.xpm", &tmp_x, &tmp_y);
	game->coin_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/coin.xpm", &tmp_x, &tmp_y);
	game->exit_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/exit.xpm", &tmp_x, &tmp_y);
}

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return (0);
	}
	write(1, "ERROR\n", 6);
	return (1);
}

static t_game	*game_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit (1);
	game->coins = 0;
	game->exit = 0;
	game->ply = 0;
	game->moves = 0;
	return (game);
}

void	start_game(char *map_name)
{
	t_game	*game;
	int		fd;

	if (filename_check(map_name))
		return ;
	game = game_init();
	fd = open(map_name, O_RDONLY);
	game->map = map_constractor(game, fd);
	close(fd);
	if (map_validation(game))
		free_game(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		free_game(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * PIXEL,
			game->map_height * PIXEL, "so_long");
	if (!game->mlx_win)
		free_game(game);
	xpm_control(game);
	load_sprite(game);
	mlx_hook(game->mlx_win, 2, 0, key_down, game);
	mlx_hook(game->mlx_win, 17, 0, game_exit, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
