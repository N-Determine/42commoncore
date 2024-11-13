/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:10:34 by adeters           #+#    #+#             */
/*   Updated: 2024/11/13 15:26:48 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_data	data;
	int		checker;

	if (ac != 2)
		return (err_pr2(9), 1);
	if (data_init(&data, av[1]) != 0)
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (free_all(data.map.map, data.map.hight), 1);
	checker = load_tiles(&data);
	if (checker != TILES)
		return (err_pr(18, 0), destroy_everything(&data, checker), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width
			* data.tiles.c.width, data.map.hight * data.tiles.c.hight,
			WINDOW_NAME);
	if (!data.win_ptr)
		return (destroy_everything(&data, TILES), 1);
	print_gamestate(&data);
	mlx_hook(data.win_ptr, 17, 0, &set_close_request, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_close_request, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	destroy_everything(&data, TILES);
	return (0);
}
