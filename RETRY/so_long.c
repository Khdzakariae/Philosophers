/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:04:36 by zel-khad          #+#    #+#             */
/*   Updated: 2024/02/26 13:48:58 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, count_map_colone(data->map) * 42,
			count_map_line(data->map) * 42, "SO_LONG");
	if (!data->win)
		return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (write(1, ANSI_COLOR_YELLOW "ENTRER UNE MAP .. !", 24));
	if (check_path(av[1]) == 0)
		return (write(1, ANSI_COLOR_YELLOW "ENTRER UN PATH VALID |.ber| !",
				34));
	if (read_map(&data, av[1]) == 0)
		return (0);
	ft_position_player(data.map, &data.player_x, &data.player_y);
	if (parssin_map(&data, data.tmp_map) == 0)
	{
		free_(data.map);
		return (EXIT_FAILURE);
	}
	init_game(&data);
	draw_player(&data, "number of moved ..|0|");
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, handle_destroy_notify, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
