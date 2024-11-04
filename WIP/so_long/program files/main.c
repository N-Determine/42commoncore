#include "so_long.h"
#include <math.h>
#include <stdio.h>


#define WWIDTH 1280
#define WHIGHT 720
#define PWIDTH 32
#define PHIGHT 32
#define WINDOW_NAME "new window"

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


int	main(void)
{
	t_images image;
	t_tiles	*tiles;
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
	


	// Getting in the map
	int test_map[5][3];
	test_map[0][0] = test_map[1][0] = test_map[2][0] = test_map[3][0] = test_map[4][0] = '1';
	test_map[0][1] = test_map[4][1] = '1';
	test_map[2][1] = test_map[1][1] = 'C';
	test_map[0][2] = test_map[1][2] = test_map[2][2] = test_map[3][2] = test_map[4][2] = '1';




	// Loading the images in the tiles struct
	tiles = malloc(sizeof(t_tiles));
	tiles->c.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/collectable.xpm", &tiles->c.width, &tiles->c.hight);
	tiles->thc.img = mlx_xpm_file_to_image(data.mlx_ptr, "../images/tile_hard_contrast.xpm", &tiles->thc.width, &tiles->thc.hight);



	// Printing the map itself
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (test_map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tiles->c.img, i * tiles->c.width, j * tiles->c.hight);
			else if (test_map[i][j] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, tiles->thc.img, i * tiles->thc.width, j * tiles->thc.hight);
		}
	}

	// Make function to free this crap
	mlx_destroy_image(data.mlx_ptr, tiles->c.img);
	mlx_destroy_image(data.mlx_ptr, tiles->thc.img);
	free(tiles);





	// Setting up hooks
	mlx_hook(data.win_ptr, 17, 0, &set_close_request, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_close_request, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);





	mlx_loop(data.mlx_ptr);






	// Getting rid of stuff
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}