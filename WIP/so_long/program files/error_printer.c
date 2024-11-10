/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:43:55 by adeters           #+#    #+#             */
/*   Updated: 2024/11/10 21:17:07 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Prints an error message to stderr using the
 * ft_putstr_fd function
 */
void	error_printer(int code)
{
	ft_putstr_fd("Error\n", 2);
	if (code == 1)
		ft_putstr_fd("Could not load map!\n",
			2);
	if (code == 2)
		ft_putstr_fd("The map is not rectangular!\n", 2);
	if (code == 3)
		ft_putstr_fd("Space for map could not be allocated!\n", 2);
	if (code == 4)
		ft_putstr_fd("GNL function failed while filling the 2D Array!\n",
			2);
	if (code == 5)
		ft_putstr_fd("Player character (P) missing in the map!\n", 2);
	if (code == 6)
		ft_putstr_fd("Too many player characters (P) in the map!\n", 2);
	if (code == 7)
		ft_putstr_fd("Exit character (E) missing in the map!\n", 2);
	if (code == 8)
		ft_putstr_fd("Too many exit characters (E) in the map!\n", 2);
	if (code == 9)
		ft_putstr_fd("Usage: ./long ../maps/map.ber\n", 2);
	if (code == 10)
		ft_putstr_fd("Not a valid map adress!\n", 2);
	if (code == 11)
		ft_putstr_fd("Map not surrounded with walls!\n", 2);
	if (code == 12)
		ft_putstr_fd("Map does not contain at least 1 collectible!\n", 2);
	if (code == 13)
		ft_putstr_fd("Map does not contain at least 1 free space!\n", 2);
	// Could include a counter quite easily
	if (code == 14)
		ft_putstr_fd("Map contains invalid characters!\n", 2);
}
