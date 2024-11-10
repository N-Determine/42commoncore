/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:29:48 by adeters           #+#    #+#             */
/*   Updated: 2024/11/10 20:22:27 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include "get_next_line.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WINDOW_NAME "new window"
# define WIN_MSG "You won. Congratulations!\n"
# define BYE_MSG "Bye bye!\n"
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
}	t_images; // Check norm for name

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
}				t_tiles;

typedef struct s_map_data
{
	int			hight;
	int			width;
	int			pos_x;
	int			pos_y;
	int			colls;
	int			colls_found;
	int			step_count;
	int			e_pos_x;
	int			e_pos_y;
	char		**map;
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
void			error_printer(int code);

// load_map.c
char			**load_map(char *map_adress, t_data *data);

// init_and_destroy.c
int				data_init(t_data *data, char *map_adress);
int				load_tiles(t_data *data);
void			free_all(char **arr, int index);
void			destroy_everything(t_data *data);

// print_gamestate.c
/**
 * @brief Prints the gamestate by going through the 2D Array of the
 * map at the current gamestate and defining which tiles to print
 * on which position.
 */
void			print_gamestate(t_data *data);

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
int				locate_pois(t_data *data);

// movement.c
/**
 * @brief Executes player movement in the specified direction.
 * 
 * This function moves the player on a 2D map based on the provided 
 * movement direction and offset values. It calculates the new position 
 * using the current position plus `move_x` and `move_y`. If the target 
 * position is reachable, it updates the player’s position on the map, 
 * increments the step count, and checks for collectibles ('C') or the exit ('e').
 * If the exit is reached, the game ends. 
 *
 * @param data Pointer to the game data structure.
 * @param dir Character representing the movement direction ('P', 'A', 'W', 'S').
 * @param move_x Integer indicating the movement offset in the x direction.
 * @param move_y Integer indicating the movement offset in the y direction.
 */
void	handle_movement(t_data *data, char dir, int move_x, int move_y);

// handle_events.c
/**
 * @brief Sets a close request flag for the application.
 *
 * This function sets a flag within the game data structure to indicate that
 * the application should close when the `handle_close_request` function
 * is called. This approach allows for a clean and controlled shutdown,
 * ensuring that all resources are properly freed before exiting.
 *
 * @param data Pointer to the game data structure containing application state.
 *
 * @return 0 Always returns 0 after setting the close request flag.
 */
int				set_close_request(t_data *data);
/**
 * @brief Handles the application's close request by freeing resources.
 *
 * This function checks if a close request has been set by `set_close_request`.
 * If so, it calls `destroy_everything` to release all allocated resources,
 * prints a goodbye message, and then exits the application. This ensures
 * a proper cleanup and prevents memory leaks or other issues.
 *
 * @param data Pointer to the game data structure containing application state.
 *
 * @return 0 Always returns 0 after handling the close request.
 */
int				handle_close_request(t_data *data);
/**
 * @brief Handles keyboard input for game controls.
 *
 * This function manages all keyboard input to control the game. It:
 *
 * - Closes the game if the Escape key is pressed, ensuring all resources
 *   are freed by calling `destroy_everything`.
 *
 * - Calls `handle_movement` to update the player's position when any of
 *   the direction keys (W, A, S, D or arrow keys) are pressed.
 *
 * - Opens the exit (changing 'E' to 'e') when all collectibles have been found.
 *
 * After processing the key press, the function calls `print_gamestate` to
 * refresh the game display with the updated state.
 *
 * @param keysym Integer representing the key symbol of the pressed key.
 * @param data Pointer to the game data structure containing application state.
 *
 * @return 0 Always returns 0 after handling the key press.
 */
int				handle_keypress(int keysym, t_data *data);

#endif
