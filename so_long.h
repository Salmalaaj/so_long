/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 07:38:03 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/02 23:05:44 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/* mlx pt / win_ptr */

typedef struct s_game{
	char	**map;
	void	*m;
	void	*wi;
	void	*astro;
	void	*space;
	void	*spship;
	void	*planet;
	void	*earth;
	void	*right;
	void	*left;
	void	*down;
	void	*up;
	int		width;
	int		height;
	int		c1;
	int		p1;
	int		e1;
	int		k;
	int		count_moves;
}	t_game;

	/* UTILS */
char	*ft_strdup(char *c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);

	/* ARGS PARAMS */
void	error_detected(void);
void	check_ber(char *str);

	/* MAP STUFF */

char	**link_map(int fd);
char	**split_map(char *map);
char	*get_next_line(int fd);
void	lines_length(t_game *game);
void	wall_turn(t_game *game);
void	sides(t_game *game);
void	check_map(t_game *g);
void	check_char(t_game *game);
void	counter(t_game *game);
void	pce(t_game *game);
void	empty_line(char *game);

	/* ANIMATION STUFF */

void	animation(t_game *game);
void	images(t_game *game);
int		key_moves(int key, t_game *game);
void	go_up(t_game *g);
void	go_down(t_game *g);
void	go_right(t_game *g);
void	go_left(t_game *g);
void	swap(t_game *game, int i, int j, int k);
void	swap2(t_game *game, int i, int j, int k);
void	exit_please(t_game *game);
int		count_c(t_game	*game);
void	display_image(t_game *game);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
char	*ft_itoa(int n);
int		exit_game(void);

#endif