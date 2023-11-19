/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:25:47 by emsakar           #+#    #+#             */
/*   Updated: 2023/10/09 17:55:11 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reset(char *buffer)
{
	int	i;

	i = 0;
	while (i < 10000)
		buffer[i++] = 0;
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	xpm_control(t_game *game)
{
	int	hero;
	int	wall;
	int	coin;
	int	exitt;
	int	floor;

	(void)game;
	hero = open("./res/hero.xpm", O_RDONLY);
	wall = open("./res/wall.xpm", O_RDONLY);
	coin = open("./res/coin.xpm", O_RDONLY);
	exitt = open("./res/exit.xpm", O_RDONLY);
	floor = open("./res/floor.xpm", O_RDONLY);
	close(hero);
	close(wall);
	close(coin);
	close(exitt);
	close(floor);
	if (hero <= 0 || wall <= 0 || coin <= 0 || exitt <= 0 || floor <= 0)
		free_game(game);
	return (0);
}
