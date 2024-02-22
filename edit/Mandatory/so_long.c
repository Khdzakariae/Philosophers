/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:04:36 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/18 10:02:03 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (write(1, ANSI_COLOR_YELLOW "ENTRER UNE MAP .. !", 24));
	if (read_map(&data, av[1]) == 0)
		return (0);
	ft_position_player(data.map, &data.player_x, &data.player_y);
	if (parssin_map(&data, data.tmp_map) == 0)
		return (free_(data.map), EXIT_FAILURE);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, count_map_colone(data.map) * 42,
			count_map_line(data.map) * 42, "SO_LONG");
	draw_player(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, handle_destroy_notify, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	free_(data.map);
	free_(data.tmp_map);
	return (EXIT_SUCCESS);
}
