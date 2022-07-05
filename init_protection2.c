/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_protection2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 04:00:58 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 04:04:11 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error!\nWrong file name :)", 25);
	exit(1);
}

void	draw_right(t_game *game)
{
	game->right = mlx_xpm_file_to_image(game->m,
			"pictures/right.xpm", &game->width, &game->height);
	if (game->right == 0)
		ft_error();
}

void	draw_left(t_game *game)
{
	game->left = mlx_xpm_file_to_image(game->m,
			"pictures/left.xpm", &game->width, &game->height);
	if (game->left == 0)
		ft_error();
}

void	draw_down(t_game *game)
{
	game->down = mlx_xpm_file_to_image(game->m,
			"pictures/down.xpm", &game->width, &game->height);
	if (game->down == 0)
		ft_error();
}

void	draw_up(t_game *game)
{
	game->up = mlx_xpm_file_to_image(game->m,
			"pictures/up.xpm", &game->width, &game->height);
	if (game->up == 0)
		ft_error();
}
