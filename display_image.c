/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 04:34:57 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 04:43:39 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->count_moves);
	images(game);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
	return ;
}
