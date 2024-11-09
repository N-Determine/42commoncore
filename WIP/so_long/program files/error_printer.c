#include "so_long.h"

/**
 * @brief Prints an error message to stderr using the
 * ft_putstr_fd function
 */
void	error_printer(int code)
{
	ft_putstr_fd("Error\n", 2);
	if (code == 1)
		ft_putstr_fd("The get_next_line function failed while loading the map!\n",
			2);
	if (code == 2)
	ft_putstr_fd("The map is not rectangular!\n",
		2);
	if (code == 3)
	ft_putstr_fd("Space for map could not be allocated!\n",
		2);
	if (code == 4)
	ft_putstr_fd("The get_next_line function failed while filling the 2D Array!\n",
		2);
	if (code == 5)
	ft_putstr_fd("Too many player characters (P) in the map!\n",
		2);
	if (code == 6)
	ft_putstr_fd("Too many exit characters (E) in the map!\n",
		2);
}