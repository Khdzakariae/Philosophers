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
	char	*s ;
	s = NULL;
	char	*ret;

	ret = NULL;
	k = open(map, O_RDONLY);
	if (k == -1)
		return (write(1, ANSI_COLOR_RED "ENTRER MAP VALID !", 24), 0);
	while (1)
	{
		s = get_next_line(k);
		if (*s == '\n')
		{
			free(s);
			break;
		}
		if (!s  ||*s == '\0')
		{
			free(s);
			break ;
		}
		ret = ft_strjoin(ret, s);
		free(s);
	}
	if (!ret)
	{
		free(ret);
		free(s);
		return (write(1, ANSI_COLOR_RED "FILLE VIDE !!", 20), 0);
	}
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

	booyah(data, data->map[px][py]);
	update_player(data, px, py, &moved);
	draw_player(data);
}
