/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:29:48 by adeters           #+#    #+#             */
/*   Updated: 2024/11/03 18:35:34 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_images
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
} 				t_images; // Check norm for name

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			close_request;
}				t_data;

unsigned int	get_rgb(unsigned char red, unsigned char green,
					unsigned char blue);

#endif
