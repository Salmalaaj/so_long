/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 08:39:48 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 04:42:32 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation(t_game *game)
{
	game->m = mlx_init();
	game->wi = mlx_new_window(game->m,
			ft_strlen(game->map[0]) * 70, game->k * 70, "Space");
	draw_astro(game);
	draw_space(game);
	draw_spship(game);
	draw_planet(game);
	draw_earth(game);
	draw_right(game);
	draw_left(game);
	draw_down(game);
	draw_up(game);
	images(game);
	mlx_key_hook(game->wi, key_moves, game);
	mlx_hook(game->wi, 17, 0, exit_game, NULL);
	mlx_loop(game->m);
}

void	images(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			mlx_put_image_to_window(g->m, g->wi, g->space, j * 70, i * 70);
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->m, g->wi, g->planet, j * 70, i * 70);
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->m, g->wi, g->astro, j * 70, i * 70);
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->m, g->wi, g->spship, j * 70, i * 70);
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->m, g->wi, g->earth, j * 70, i * 70);
			j++;
		}
		i++;
	}
}

int	key_moves(int key, t_game *game)
{
	if (key == 13 || key == 126)
		go_up(game);
	if (key == 0 || key == 123)
		go_left(game);
	if (key == 1 || key == 125)
		go_down(game);
	if (key == 2 || key == 124)
		go_right(game);
	if (key == 53)
		exit(0);
	return (0);
}

void	empty_line(char *game)
{
	int	i;

	i = 0;
	while (game[i])
	{
		if (game[0] == '\n' || (game[i] == '\n' && game[i + 1] == '\n'))
		{
			write(2, "Error!\nYou added an empty line :)", 33);
			exit(1);
		}
	i++;
	}
}
