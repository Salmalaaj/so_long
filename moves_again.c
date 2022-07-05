/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:40:34 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 05:00:43 by slaajour         ###   ########.fr       */
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

int	exit_game(void)
{
	exit(1);
}

void	exit_please(t_game *game)
{
	game->count_moves++;
	write(1, "Congratulations budy <3 You are in earth!!\n", 43);
	exit(0);
}

void	error_wall(void)
{
	write(2, "Error!\n1 is missing in the wall :)", 34);
	exit(1);
}
