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
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	/*
	// Make the functions work with all playable varieties
	if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		update_game_state(a);
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		update_game_state(d);
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		update_game_state(w);
	if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		update_game_state(s);*/
	return (0);
}

/**
 * @brief Loads all the seperate images into the tiles struct
 */
int	load_tiles(t_data data, t_tiles *tiles)
{
	tiles->c.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/c.xpm",
			&tiles->c.width, &tiles->c.hight);
	tiles->ec.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/ec.xpm",
			&tiles->ec.width, &tiles->ec.hight);
	tiles->eo.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/eo.xpm",
			&tiles->eo.width, &tiles->eo.hight);
	tiles->pd.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/pd.xpm",
			&tiles->pd.width, &tiles->pd.hight);
	tiles->pl.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/pl.xpm",
			&tiles->pl.width, &tiles->pl.hight);
	tiles->pr.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/pr.xpm",
			&tiles->pr.width, &tiles->pr.hight);
	tiles->pu.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/pu.xpm",
			&tiles->pu.width, &tiles->pu.hight);
	tiles->thc.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/thc.xpm",
			&tiles->thc.width, &tiles->thc.hight);
	if (!tiles->c.img || !tiles->ec.img || !tiles->eo.img)
		return (0);
	if (!tiles->pd.img || !tiles->pl.img || !tiles->pr.img || !tiles->pu.img)
		return (0);
	if (!tiles->thc.img) // Don't forget the ghosts
		return (0);
	return (1);
}

int	main(void)
{
	t_images image;
	t_tiles *tiles;
	t_data data;
	data.close_request = 0;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WWIDTH, WHIGHT, WINDOW_NAME);

	/*
	// Image Creation
	image.img = mlx_new_image(data.mlx_ptr, WWIDTH, WHIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, image.img, 0, 0);
	mlx_destroy_image(data.mlx_ptr, image.img);
	*/




	/*
	// Getting in the map
	int map_width = 5;
	int map_hight = 3;
	int test_map[map_width][map_hight];
	test_map[0][0] = 'E';
	test_map[1][0] = 'e';
	test_map[2][0] = 'W';
	test_map[3][0] = 'A';
	test_map[4][0] = 'S';
	test_map[0][1] = 'P';
	test_map[4][1] = '1';
	test_map[2][1] = test_map[1][1] = 'C';
	test_map[0][2] = test_map[1][2] = test_map[2][2] = test_map[3][2] = test_map[4][2] = '1';
	int width = map_width;
	int hight = map_hight;
	*/



	int width; 
	int hight;
	char **test_map = load_map(MAP_ADRESS, &width, &hight);
	if (!test_map)
		return (1);














	// Make space for the tiles struct and load the images
	tiles = malloc(sizeof(t_tiles)); // Protect
	load_tiles(data, tiles);         // Protect



	

	// Print current gamestate (aka the map after making adjustments)
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (test_map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->c.img, j * tiles->c.width, i * tiles->c.hight);
			else if (test_map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->ec.img, j * tiles->ec.width, i * tiles->ec.hight);
			else if (test_map[i][j] == 'e')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->eo.img, j * tiles->eo.width, i * tiles->eo.hight);
			else if (test_map[i][j] == 'S')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->pd.img, j * tiles->pd.width, i * tiles->pd.hight);
			else if (test_map[i][j] == 'A')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->pl.img, j * tiles->pl.width, i * tiles->pl.hight);
			else if (test_map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->pr.img, j * tiles->pr.width, i * tiles->pr.hight);
			else if (test_map[i][j] == 'W')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->pu.img, j * tiles->pu.width, i * tiles->pu.hight);
			else if (test_map[i][j] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					tiles->thc.img, j * tiles->thc.width, i * tiles->thc.hight);
		}
	}

	// Setting up hooks
	mlx_hook(data.win_ptr, 17, 0, &set_close_request, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_close_request, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	// Make function to free this crap
	mlx_destroy_image(data.mlx_ptr, tiles->c.img);
	mlx_destroy_image(data.mlx_ptr, tiles->ec.img);
	mlx_destroy_image(data.mlx_ptr, tiles->eo.img);
	mlx_destroy_image(data.mlx_ptr, tiles->pd.img);
	mlx_destroy_image(data.mlx_ptr, tiles->pl.img);
	mlx_destroy_image(data.mlx_ptr, tiles->pr.img);
	mlx_destroy_image(data.mlx_ptr, tiles->pu.img);
	mlx_destroy_image(data.mlx_ptr, tiles->thc.img); // Don't forget the ghosts
	free(tiles);

	// Getting rid of stuff
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}