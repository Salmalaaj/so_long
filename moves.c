/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:50:05 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/04 16:01:58 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	g->spship = g->up;
	while (g->map[++i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P' && g->map[i - 1][j] != '1')
			{
				if (g->map[i - 1][j] == '0')
					swap(g, i, j, i - 1);
				else if (g->map[i - 1][j] == 'C')
					swap(g, i, j, i - 1);
				else if (g->map[i - 1][j] == 'E')
					if (count_c(g) == 0)
						exit_please(g);
				display_image(g);
				return ;
			}
			j++;
		}
	}
}

void	go_down(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	g->spship = g->down;
	while (g->map[++i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P' && g->map[i + 1][j] != '1')
			{
				if (g->map[i + 1][j] == '0')
					swap(g, i, j, i + 1);
				else if (g->map[i + 1][j] == 'C')
					swap(g, i, j, i + 1);
				else if (g->map[i + 1][j] == 'E')
					if (count_c(g) == 0)
						exit_please(g);
				display_image(g);
				return ;
			}
			j++;
		}
	}
}

void	go_right(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	g->spship = g->right;
	while (g->map[++i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P' && g->map[i][j + 1] != '1')
			{
				if (g->map[i][j + 1] == '0')
					swap2(g, i, j, j + 1);
				else if (g->map[i][j + 1] == 'C')
					swap2(g, i, j, j + 1);
				else if (g->map[i][j + 1] == 'E')
					if (count_c(g) == 0)
						exit_please(g);
				display_image(g);
				return ;
			}
			j++;
		}
	}
}

void	go_left(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	g->spship = g->left;
	while (g->map[++i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P' && g->map[i][j - 1] != '1')
			{
				if (g->map[i][j - 1] == '0')
					swap2(g, i, j, j - 1);
				else if (g->map[i][j - 1] == 'C')
					swap2(g, i, j, j - 1);
				else if (g->map[i][j - 1] == 'E')
					if (count_c(g) == 0)
						exit_please(g);
				display_image(g);
				return ;
			}
			j++;
		}
	}
}

int	count_c(t_game	*game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j + 1] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
