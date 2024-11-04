/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:29:48 by adeters           #+#    #+#             */
/*   Updated: 2024/11/04 21:45:40 by adeters          ###   ########.fr       */
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
	int			width;
	int			hight;
} 				t_images; // Check norm for name


/**
 * @brief Struct that holds all of the images needed to print the map
 * 
 * @param c Collectable -			Code: `C`
 * @param ec Exit Closed -			Code: `E`
 * @param eo Exit Opened -			Code: `e`
 * @param pd Player Down -			Code: `S`
 * @param pl Player Left -			Code: `A`
 * @param pr Player Right -			Code: `P`
 * @param pu Player Up -			Code: `W`
 * @param thc Tile Hard Contrast -	Code: `1`
 */
typedef struct s_tiles
{
	t_images	c;
	t_images	ec;
	t_images	eo;
	t_images	pd;
	t_images	pl;
	t_images	pr;
	t_images	pu;
	t_images	thc;
}	t_tiles;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			close_request;
}				t_data;

unsigned int	get_rgb(unsigned char red, unsigned char green,
					unsigned char blue);

#endif
