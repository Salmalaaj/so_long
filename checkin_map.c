/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:30:26 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/07 05:04:39 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_turn(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1')
			error_wall();
		j++;
	}
	while (game->map[i])
		i++;
	while (game->map[i - 1][k])
	{
		if (k == ft_strlen(game->map[i - 1]) && game->map[i - 1][k] != '\0')
			error_wall();
		else if (game->map[i - 1][k] != '1')
			error_wall();
		k++;
	}
}

void	sides(t_game *game)
{
	int		i;
	int		len;

	i = 0;
	len = strlen(game->map[0]);
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
		{
			write(2, "Error!\n1 is missing in the wall :)", 34);
			exit (1);
		}
		else
			i++;
	}
}

void	check_map(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] != 'P' && g->map[i][j] != 'C' &&
				g->map[i][j] != 'E' && g->map[i][j] != '1' &&
				g->map[i][j] != '0')
			{
				write(2, "Error!\nDifferent character is added :)\n", 39);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	counter(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->p1 = 0;
	game->c1 = 0;
	game->e1 = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p1++;
			else if (game->map[i][j] == 'C')
				game->c1++;
			else if (game->map[i][j] == 'E')
				game->e1++;
			j++;
		}
		i++;
	}
	pce(game);
}

void	pce(t_game *game)
{
	if (game->p1 != 1)
	{
		write(2, "Error!\nThere should be one player :)", 36);
		exit(1);
	}
	if (game->c1 < 1 || game->e1 < 1)
	{
		write(2, "Error!\nOne collectible/exit is missing :)", 41);
		exit(1);
	}
}
