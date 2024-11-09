/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:29:48 by adeters           #+#    #+#             */
/*   Updated: 2024/11/09 22:28:49 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"


# define PWIDTH 32
# define PHIGHT 32
# define WINDOW_NAME "new window"
# define MAP_ADRESS "../maps/minimal.ber"

// Structs
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
 * @param zero Nothing - Code `0`
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
	t_images	zero;
}	t_tiles;

typedef struct	s_map_data
{
	int hight;
	int width;
	int pos_x;
	int pos_y;
	int colls;
	int colls_found;
	int step_count;
	int e_pos_x;
	int e_pos_y;
	char **map;
}				t_map_data;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			close_request;
	t_map_data	map;
	t_tiles		tiles;
}				t_data;

// error_printer.c
/**
 * @brief Prints an error message to stderr using the 
 * ft_putstr_fd function
 */
void error_printer(int code);

// load_map.c
char	**load_map(char *map_adress, int *width, int *hight);

// init_and_destroy.c
int		data_init(t_data *data);
int		load_tiles(t_data *data, t_tiles tiles);
void	free_all(char **arr, int index);
void	destroy_everything(t_data *data);

// print_gamestate.c
/**
 * @brief Prints the gamestate by going through the 2D Array of the 
 * map at the current gamestate and defining which tiles to print 
 * on which position.
 */
void	print_gamestate(t_data *data);

// locate_pois.c
/**
 * @brief Locates points of interest by setting the coordinates of 
 * the player and the exit. At the same time the amount of 
 * collectables is counted.
 * 
 * @return `-1` - if multiple players or exits have been spotted
 * 
 * `0`- if the location process was successful
 */
int locate_pois(t_data *data);

#endif
