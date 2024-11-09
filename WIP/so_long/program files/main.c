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

void	print_gamestate(t_data *data)
{
	int i;
	int j;

	i = 0;
	while(i < data->map.hight)
	{
		j = 0;
		while(j < data->map.width)
		{
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.c.img, j * data->tiles.c.width, i * data->tiles.c.hight);
			else if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.ec.img, j * data->tiles.ec.width, i * data->tiles.ec.hight);
			else if (data->map.map[i][j] == 'e')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.eo.img, j * data->tiles.eo.width, i * data->tiles.eo.hight);
			else if (data->map.map[i][j] == 'S')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.pd.img, j * data->tiles.pd.width, i * data->tiles.pd.hight);
			else if (data->map.map[i][j] == 'A')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.pl.img, j * data->tiles.pl.width, i * data->tiles.pl.hight);
			else if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.pr.img, j * data->tiles.pr.width, i * data->tiles.pr.hight);
			else if (data->map.map[i][j] == 'W')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.pu.img, j * data->tiles.pu.width, i * data->tiles.pu.hight);
			else if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.thc.img, j * data->tiles.thc.width, i * data->tiles.thc.hight);
			else if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.zero.img, j * data->tiles.zero.width, i * data->tiles.zero.hight);
			j++;
		}
		i++;
	}
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

/**
 * @brief Loads all the seperate images into the tiles struct
 */
int	load_tiles(t_data *data, t_tiles tiles)
{
	data->tiles.c.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/c.xpm",
			&data->tiles.c.width, &data->tiles.c.hight);
	data->tiles.ec.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/ec.xpm",
			&data->tiles.ec.width, &data->tiles.ec.hight);
	data->tiles.eo.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/eo.xpm",
			&data->tiles.eo.width, &data->tiles.eo.hight);
	data->tiles.pd.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/pd.xpm",
			&data->tiles.pd.width, &data->tiles.pd.hight);
	data->tiles.pl.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/pl.xpm",
			&data->tiles.pl.width, &data->tiles.pl.hight);
	data->tiles.pr.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/pr.xpm",
			&data->tiles.pr.width, &data->tiles.pr.hight);
	data->tiles.pu.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/pu.xpm",
			&data->tiles.pu.width, &data->tiles.pu.hight);
	data->tiles.thc.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/thc.xpm",
			&data->tiles.thc.width, &data->tiles.thc.hight);
	data->tiles.zero.img = mlx_xpm_file_to_image(data->mlx_ptr, "../images/0.xpm",
			&data->tiles.zero.width, &data->tiles.zero.hight);
	if (!data->tiles.c.img || !data->tiles.ec.img || !data->tiles.eo.img)
		return (-1);
	if (!data->tiles.pd.img || !data->tiles.pl.img || !data->tiles.pr.img || !data->tiles.pu.img)
		return (-1);
	if (!data->tiles.thc.img) // Don't forget the ghosts
		return (-1);
	return (1);
}

int	data_init(t_data *data)
{
	// make some kind of init function for data
	data->close_request = 0;
	data->map.colls_found = 0;
	data->map.step_count = 0;
	data->close_request = 0;
	data->map.map = load_map(MAP_ADRESS, &data->map.width, &data->map.hight);
	if (!data->map.map)
		return (-1);
	if (locate_pois(data) == -1)
		return (-2);
	return (1);
}

int	main(void)
{
	t_data data;

	if (data_init(&data) < 0)
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	if (load_tiles(&data, data.tiles) < 0)
		return (1);
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