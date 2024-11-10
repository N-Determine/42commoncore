#include "so_long.h"

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
		ft_putstr_fd("Bye bye!\n", 1);
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		destroy_everything(data);
		ft_putstr_fd("Bye bye!\n", 1);
		exit(0);
	}
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		handle_movement(data, 'P');
	if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		handle_movement(data, 'A');
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		handle_movement(data, 'W');
	if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		handle_movement(data, 'S');
	if (data->map.colls_found == data->map.colls)
		data->map.map[data->map.e_pos_y][data->map.e_pos_x] = 'e';
	print_gamestate(data);
	return (0);
}