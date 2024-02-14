/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:42:55 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/12 18:46:31 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

long long	the_time(void)
{
	struct timeval	time_;

	gettimeofday(&time_, NULL);
	return (time_.tv_sec * 1000LL + time_.tv_usec / 1000);
}

bool	timing(void)
{
	static clock_t	start_time;
	clock_t			current_time;

	current_time = the_time();
	if (start_time == 0)
		return (start_time = current_time, true);
	else if ((current_time - start_time) <= 300)
		return (false);
	start_time = 0;
	return (true);
}

char	*get_assets(const int current_image)
{
	char	*assets;
	char	*number;

	assets = malloc(20 * sizeof(char));
	number = ft_itoa(current_image);
	bzero(assets, 20);
	ft_strcat(assets, "pictures/");
	ft_strcat(assets, number);
	ft_strcat(assets, ".xpm");
	free(number);
	return (assets);
}

void	display_frame(t_data *data, char *assets, int i, int j)
{
	int	images_size;

	data->sprint = mlx_xpm_file_to_image(data->mlx, assets, &images_size,
			&images_size);
	mlx_put_image_to_window(data->mlx, data->win, data->sprint, j * 42, i * 42);
	mlx_destroy_image(data->mlx, data->sprint);
}

int	update_frame(t_data *data)
{
	static int	n_img = 4;
	char		*assets;
	int			i;
	int			j;

	if (!timing())
		return (1);
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'Z' && n_img < 12)
			{
				assets = get_assets(n_img++);
				display_frame(data, assets, i, j);
				free(assets);
			}
			else if (data->map[i][j] == 'Z' && n_img <= 12)
				n_img = 4;
		}
	}
	return (1);
}
