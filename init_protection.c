/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_protection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:33:12 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 04:01:27 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_astro(t_game *game)
{
	game->astro = mlx_xpm_file_to_image(game->m,
			"pictures/astro.xpm", &game->width, &game->height);
	if (game->astro == 0)
		ft_error();
}

void	draw_space(t_game *game)
{
	game->space = mlx_xpm_file_to_image(game->m,
			"pictures/space.xpm", &game->width, &game->height);
	if (game->space == 0)
		ft_error();
}

void	draw_spship(t_game *game)
{
	game->spship = mlx_xpm_file_to_image(game->m,
			"pictures/spship.xpm", &game->width, &game->height);
	if (game->spship == 0)
		ft_error();
}

void	draw_planet(t_game *game)
{
	game->planet = mlx_xpm_file_to_image(game->m,
			"pictures/planet.xpm", &game->width, &game->height);
	if (game->planet == 0)
		ft_error();
}

void	draw_earth(t_game *game)
{
	game->earth = mlx_xpm_file_to_image(game->m,
			"pictures/earth.xpm", &game->width, &game->height);
	if (game->earth == 0)
		ft_error();
}
