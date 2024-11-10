#include "so_long.h"
#include <math.h>
#include <stdio.h>

int	main(void)
{
	t_data data;

	if (data_init(&data) != 0)
		return (1); // Free map
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1); // Free map
	if (load_tiles(&data, data.tiles) < 0)
		return (1); // Free
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * data.tiles.c.width, data.map.hight * data.tiles.c.hight, WINDOW_NAME);
	if (!data.win_ptr)
		return (1);
	print_gamestate(&data);
	mlx_hook(data.win_ptr, 17, 0, &set_close_request, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_close_request, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	destroy_everything(&data);
	return (0);
}