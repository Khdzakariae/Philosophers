/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:51:05 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/22 22:36:06 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_destroy_notify(t_data *data)
{
	write(1, ANSI_COLOR_YELLOW "THE GMAE IS OVER", 21);
	mlx_destroy_window(data->mlx, data->win);
	free_(data->map);
	exit(1);
}

int	key_hook(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		write(1, ANSI_COLOR_YELLOW "THE GMAE IS OVER", 21);
		mlx_destroy_window(data->mlx, data->win);
		free_(data->map);
		exit(1);
	}
	if (keysym == 123 || keysym == 0)
	{
		move_player(data, data->player_x, data->player_y - 1);
	}
	else if (keysym == 124 || keysym == 2)
	{
		move_player(data, data->player_x, data->player_y + 1);
	}
	else if (keysym == 125 || keysym == 1)
	{
		move_player(data, data->player_x + 1, data->player_y);
	}
	else if (keysym == 126 || keysym == 13)
	{
		move_player(data, data->player_x - 1, data->player_y);
	}
	return (0);
}
