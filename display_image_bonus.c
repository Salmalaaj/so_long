/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 04:34:53 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 04:44:04 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
