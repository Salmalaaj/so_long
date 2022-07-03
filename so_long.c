/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 07:40:52 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/02 23:09:11 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_detected(void)
{
	write(1, "Oupsie! Error!\nNumber of arguments is invalid :)\n", 49);
	exit (0);
}

void	check_ber(char *str)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 0;
	ber = "reb.";
	while (str[i])
		i++;
	i--;
	while (ber[j])
	{
		if (ber[j] != str[i])
		{
			write(1, "Oupsie! Error!\nThe file should be ended by .ber :)\n", 51);
			exit (0);
		}
		i--;
		j++;
	}
}

char	**link_map(int fd)
{
	char	**split_map;
	char	*line;
	char	*map;
	char	*for_free;

	for_free = NULL;
	line = ft_strdup("");
	map = get_next_line(fd);
	while (line != NULL)
	{
		map = ft_strjoin(map, line);
		free (line);
		line = get_next_line(fd);
		for_free = map;
	}
	free(for_free);
	empty_line(map);
	split_map = ft_split(map, '\n');
	return (split_map);
}

void	lines_length(t_game *game)
{
	int		len;
	int		j;

	game->k = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[game->k])
	{
		j = ft_strlen(game->map[game->k]);
		if (j != len)
		{
			write(1, "Oupsie! Error!\nLines are not equal :)", 37);
			exit(1);
		}
		game->k++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc == 2)
	{
		check_ber(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		game.map = link_map(fd);
		lines_length(&game);
		wall_turn(&game);
		sides(&game);
		check_map(&game);
		counter(&game);
		animation(&game);
	}
	else
		error_detected();
}
