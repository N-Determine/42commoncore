#include "so_long.h"

#define WWIDTH 1280
#define WHIGHT 720
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