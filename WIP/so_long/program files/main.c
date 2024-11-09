#include "so_long.h"
#include <math.h>
#include <stdio.h>

int	set_close_request(t_data *data)
{
	data->close_request = 1;
	return (0);
}

int	handle_close_request(t_data *data)
{
	if (data->close_request == 1)
	{
		destroy_everything(data);
		printf("Bye bye!\n"); // Don't forget printf
		exit(0);
	}
	return (0);
}



// Refactor to be only one function maybe?
int handle_right(t_map_data *map, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr); // Protect
	
	if (map->map[map->pos_y][map->pos_x + 1] != '1' && map->map[map->pos_y][map->pos_x + 1] != 'E')
	{

		data->map.step_count++;
		printf("Step %i\n", data->map.step_count);
		if (map->map[map->pos_y][map->pos_x + 1] == 'C')
			data->map.colls_found += 1;
		if (map->map[map->pos_y][map->pos_x + 1] == 'e')
		{
			printf("You won. Congratulations!\n"); // don't forget printf
			destroy_everything(data);
			exit(0); // free shit
		}
		map->map[map->pos_y][map->pos_x] = '0';
		map->map[map->pos_y][map->pos_x + 1] = 'P';
		map->pos_x++;
	}
	return (map->pos_x);
}

int handle_left(t_map_data *map, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr); // Protect
	if (map->map[map->pos_y][map->pos_x - 1] != '1' && map->map[map->pos_y][map->pos_x - 1] != 'E')
	{
		data->map.step_count++;
		printf("Step %i\n", data->map.step_count);
		if (map->map[map->pos_y][map->pos_x - 1] == 'C')
			data->map.colls_found += 1;
		if (map->map[map->pos_y][map->pos_x - 1] == 'e')
		{
			printf("You won. Congratulations!\n"); // don't forget printf
			destroy_everything(data);
			exit(0); // free shit
		}
		map->map[map->pos_y][map->pos_x] = '0';
		map->map[map->pos_y][map->pos_x - 1] = 'A';
		map->pos_x--;
	}
	return (map->pos_x);
}

int handle_up(t_map_data *map, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr); // Protect
	if (map->map[map->pos_y - 1][map->pos_x] != '1' && map->map[map->pos_y - 1][map->pos_x] != 'E')
	{
		data->map.step_count++;
		printf("Step %i\n", data->map.step_count);
		if (map->map[map->pos_y - 1][map->pos_x] == 'C')
			data->map.colls_found += 1;
		if (map->map[map->pos_y - 1][map->pos_x] == 'e')
		{
			printf("You won. Congratulations!\n"); // don't forget printf
			destroy_everything(data);
			exit(0); // free shit
		}
		map->map[map->pos_y][map->pos_x] = '0';
		map->map[map->pos_y - 1][map->pos_x] = 'W';
		map->pos_y--;
	}
	return (map->pos_y);
}

int handle_down(t_map_data *map, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr); // Protect
	if (map->map[map->pos_y + 1][map->pos_x] != '1' && map->map[map->pos_y + 1][map->pos_x] != 'E')
	{
		data->map.step_count++;
		printf("Step %i\n", data->map.step_count);
		if (map->map[map->pos_y + 1][map->pos_x] == 'C')
			data->map.colls_found += 1;
		if (map->map[map->pos_y + 1][map->pos_x] == 'e')
		{
			printf("You won. Congratulations!\n"); // don't forget printf
			destroy_everything(data);
			exit(0); // free shit
		}
		map->map[map->pos_y][map->pos_x] = '0';
		map->map[map->pos_y + 1][map->pos_x] = 'S';
		map->pos_y++;
	}
	return (map->pos_y);
}

int	handle_keypress(int keysym, t_data *data, t_map_data *map)
{
	if (keysym == XK_Escape)
	{
		destroy_everything(data);
		printf("Bye bye!\n"); // don't forget printf
		exit(0);
	}
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		handle_right(&data->map, data);
	if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		handle_left(&data->map, data);
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		handle_up(&data->map, data);
	if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		handle_down(&data->map, data);
	if (data->map.colls_found == data->map.colls)
		data->map.map[data->map.e_pos_y][data->map.e_pos_x] = 'e';
	print_gamestate(data);
	return (0);
}

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