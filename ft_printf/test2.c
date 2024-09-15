#include <stdarg.h>

/**
 * @brief This function checks the type of the variable used in the ft_printf function
 * @param ptr Position of the variable that needs to be checked for the type
 * @return An individual code for every type that the ft_printf function can display
 * 
 * 0 = Type not found
 * 
 * 1 = A Single Character
*/
static int	ft_check_type(const char *ptr)
{
	if (ptr[1] == '\0')
		return (0);
	if (ptr[1] == 'c')
		return (1);
	if (ptr[1] == 's')
		return (2);
	if (ptr[1] == 'p')
		return (3);
	if (ptr[1] == 'd')
		return (4);
	if (ptr[1] == 'i')
		return (5);
	if (ptr[1] == 'u')
		return (6);
	if (ptr[1] == 'x')
		return (7);
	if (ptr[1] == 'X')
		return (8);
	if (ptr[1] == '%')
		return (9);
}

/**
 * @brief The function takes a code indicating the type that needs to be printed
 * Depending on the type it calls a function to print the corresponding type
 * @param ptr The position of the string that needs to be checked
 * @param var Probably is going to need to be able to take a variable as input
*/
static void	ft_print_var(const char *ptr)
{
	if (ptr[1] == '#')
		ft_putstr_fd("Some Error Message", 2);
	if (code == 1)
		ft_putstr_fd(the variable name, 1);
	if (ptr[1] == 'c')
		ft_putchar_fd(ptr[2])

}

int	ft_printf(const char *, ...)
{
	int i;
	char *str;

	i = 0;
	str = // Get the string from the first argument with the va functions
	//print the string until the end
	while (str[i])
	{
		// if variable indicated by %s etc is found -> printf variable with the corresponding type
		if (str[i] == '%')
		{
			// Check for the type and then print the variable
			print_var(check_type(&str[i]))
			i++;
		}
		i++;
	}
}