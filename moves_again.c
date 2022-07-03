/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:40:34 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/02 22:55:57 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap(t_game *game, int i, int j, int k)
{
	game->map[i][j] = '0';
	game->map[k][j] = 'P';
	game->count_moves++;
}

void	swap2(t_game *game, int i, int j, int k)
{
	game->map[i][j] = '0';
	game->map[i][k] = 'P';
	game->count_moves++;
}

void	display_image(t_game *game)
{
	char	*bonus;

	bonus = ft_itoa(game->count_moves);
	images(game);
	mlx_string_put(game->m, game->wi, 10, 10, 0xffffffff, "Moves = ");
	mlx_string_put(game->m, game->wi, 90, 10, 0xffffffff, bonus);
	free (bonus);
	return ;
}

void	exit_please(t_game *game)
{
	game->count_moves++;
	write(1, "Congratulations budy <3 You are in earth!!\n", 43);
	exit(0);
}
