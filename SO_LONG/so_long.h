/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:25:17 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/17 10:52:41 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <errno.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define ANSI_COLOR_BLACK "\x1b[30m"
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_STYLE_ITALIC "\x1b[3m"

# define EMOGE "pictures1/kkkk.xpm"
# define SPACE "pictures1/space.xpm"
# define WALL "pictures1/wall.xpm"
# define PIZZA "pictures1/pizza.xpm"
# define SORTIE "pictures1/bab.xpm"
# define SORTIEM "pictures1/baba.xpm"
# define GAME "pictures1/game.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	char	**map;
	char	**tmp_map;
	void	*sprint;
}			t_data;

void		display_frame(t_data *data, char *assets, int i, int j);
void		update_player(t_data *data, int px, int py, int *moved_number);
void		booyah(t_data *data, char target);
void		game_over(t_data *data, char target);

void		free_(char **map);
int			handle_destroy_notify(t_data *data);
int			read_map(t_data *data, char *map);
char		**ft_tmp_map(char **map);
int			parssin_map(t_data *data, char **tmp_map);
int			cheack_parssin_sortie(char **map, size_t tmp, size_t smp);

char		*ft_strcat(char *dest, char *src);
int			check_wall1(char **map);
int			check_wall2(char **map);
int			check_wall3(char **map);
int			check_wall4(char **map);

size_t		count_map_line(char **map);
size_t		count_map_colone(char **map);
void		ft_position_player(char **map, int *x, int *y);
size_t		ft_check_collective(char **map);
size_t		ft_check_enemy(char **map);
int			autr_caracters(char **map);

long long	the_time(void);
int			update_frame(t_data *data);
int			cheack_colone_map(char **map);

int			key_hook(int keysym, t_data *data);

size_t		ft_check_player(char **map);
size_t		ft_check_collective1(char **map);
size_t		ft_check_sortie(char **map);
int			cheack_map(char **map);
void		ft_strlcpy1(char **dst, char **src, size_t colon, size_t line);

void		flood_fill(char **map, int pos_x, int pos_y);
void		draw_player(t_data *data, char *moved);
void		move_player(t_data *data, int px, int py);

#endif