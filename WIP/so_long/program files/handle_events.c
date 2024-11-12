/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:45:06 by adeters           #+#    #+#             */
/*   Updated: 2024/11/12 14:24:14 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_putstr_fd(BYE_MSG, 1);
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		destroy_everything(data);
		ft_putstr_fd(BYE_MSG, 1);
		exit(0);
	}
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		handle_movement(data, 'P', 1, 0);
	if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		handle_movement(data, 'A', -1, 0);
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		handle_movement(data, 'W', 0, -1);
	if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		handle_movement(data, 'S', 0, 1);
	if (data->map.colls_found == data->map.colls)
		data->map.map[data->map.e_pos_y][data->map.e_pos_x] = 'e';
	print_gamestate(data);
	return (0);
}
