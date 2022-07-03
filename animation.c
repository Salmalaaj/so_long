/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 08:39:48 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/02 23:08:58 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation(t_game *game)
{
	game->m = mlx_init();
	game->wi = mlx_new_window(game->m,
			ft_strlen(game->map[0]) * 70, game->k * 70, "Space");
	game->astro = mlx_xpm_file_to_image(game->m,
			"pictures/astro.xpm", &game->width, &game->height);
	game->space = mlx_xpm_file_to_image(game->m,
			"pictures/space.xpm", &game->width, &game->height);
	game->spship = mlx_xpm_file_to_image(game->m,
			"pictures/spship.xpm", &game->width, &game->height);
	game->planet = mlx_xpm_file_to_image(game->m,
			"pictures/planet.xpm", &game->width, &game->height);
	game->earth = mlx_xpm_file_to_image(game->m,
			"pictures/earth.xpm", &game->width, &game->height);
	game->right = mlx_xpm_file_to_image(game->m,
			"pictures/right.xpm", &game->width, &game->height);
	game->left = mlx_xpm_file_to_image(game->m,
			"pictures/left.xpm", &game->width, &game->height);
	game->down = mlx_xpm_file_to_image(game->m,
			"pictures/down.xpm", &game->width, &game->height);
	game->up = mlx_xpm_file_to_image(game->m,
			"pictures/up.xpm", &game->width, &game->height);
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
			write(1, "Oupsie! Error!\nYou added a new line :)", 38);
			exit(0);
		}
	i++;
	}
}

int	exit_game(void)
{
	exit(0);
}
