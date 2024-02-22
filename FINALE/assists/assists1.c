/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assists1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:58:26 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/22 22:33:12 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_(char **map)
{
	size_t	i;
	size_t	tmp;

	tmp = count_map_line(map);
	i = 0;
	while (i < tmp)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	read_map(t_data *data, char *map)
{
	int		k;
	char	*s;
	char	*ret;

	ret = NULL;
	k = open(map, O_RDONLY);
	if (k == -1)
		return (write(1, ANSI_COLOR_RED "ENTRER MAP VALID !", 24), 0);
	while (1)
	{
		s = get_next_line(k);
		if (!s || *s == '\0' || *s == '\n')
		{
			free(s);
			break ;
		}
		ret = ft_strjoin(ret, s);
		free(s);
	}
	if (!ret)
		return (write(1, ANSI_COLOR_RED "FILLE VIDE !!", 20), 0);
	data->map = ft_split(ret, 10);
	data->tmp_map = ft_split(ret, 10);
	free(ret);
	return (close(k), 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

void	move_player(t_data *data, int px, int py)
{
	static int	moved = 1;
	char		*number_of_moved;
	char		*number;

	number = ft_itoa(moved);
	number_of_moved = ft_calloc(30, sizeof(char));
	ft_strcat(number_of_moved, "number of movements ..");
	ft_strcat(number_of_moved, number);
	free(number);
	game_over(data, data->map[px][py]);
	booyah(data, data->map[px][py]);
	update_player(data, px, py, &moved);
	draw_player(data, number_of_moved);
	free(number_of_moved);
}
