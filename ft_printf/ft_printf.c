/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:13:24 by adeters           #+#    #+#             */
/*   Updated: 2024/09/15 19:06:22 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Lets make the most simple printf possible as a first test
 */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

static int	ft_is_specifier(char c);
static void	ft_var_printer(char code, va_list list);
static void	ft_puthexas_fd(char code, va_list list, int fd);


int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		// Instead loop from % until a specifier or \0 -> Error
		// Create a function that checks for flags etc. within the loop
		// Counter für die Minimum Width
		if (str[i] == '%' && ft_is_specifier(str[i + 1]))
		{
			ft_var_printer(str[i + 1], args);
			i += 2;
		}
		if (str[i] && str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (1);
}

/**
 * @brief Checks if the input character is a specifier or
	% (in contrast to a flag)
 *
 * @param c The character that needs to be checked
 *
 * @return 1 - If the character is a specifier (or %)
 *
 * 			0 - If the charater is no a specifier (or %)
 */
static int	ft_is_specifier(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

/**
 * @brief Prints the content of the list using a differnt function to print it
 * depending of the type of content it contains
 *
 * @param code The specifier that decides what function needs to be used to
 * print the content
 * @param list The pointer to the va_list in which the content 
 * needs to be printed
 */
static void	ft_var_printer(char code, va_list list)
{
	char *ptr;

	ptr = 0;
	if (code == 's')
	{
		ptr = va_arg(list, char *);
		if (ptr != 0)
			ft_putstr_fd(ptr, 1);
		else
			ft_putstr_fd("(null)", 1);
	}
	else if (code == 'c')
		ft_putchar_fd((char)va_arg(list, int), 1);
	else if (code == 'i' || code == 'd')
		ft_putnbr_fd(va_arg(list, int), 1);
	else if (code == 'u')
		ft_putunbr_fd(va_arg(list, unsigned int), 1);
	else if (code == '%')
		ft_putchar_fd('%', 1);
	else if (code == 'p' || code == 'x' || code == 'X')
		ft_puthexas_fd(code, list, 1);
}

/**
 * @brief Saves lines for the `ft_var_printer` function.
 *
 * This function is responsible for handling and saving lines related to 
 * the formatting and printing of data by the `ft_var_printer` function.
 *
 * @param code A character representing the format specifier:
 * 
 *             - `'p'`: Pointer address
 * 
 *             - `'x'`: Number in lowercase hexadecimal
 * 
 *             - `'X'`: Number in uppercase hexadecimal
 *
 * @param list A pointer to the same list of variables used by `ft_var_printer`.
 *             This list contains the values to be formatted and printed.
 *
 * @param fd The file descriptor where the output is printed.
 *           Typically, this should be `1` for standard output
 * 				in the ft_var_printer function.
 */
static void	ft_puthexas_fd(char code, va_list list, int fd)
{
	long long vptr;

	if (code == 'p')
	{
		vptr = (long long)va_arg(list, void *);
		if (vptr != 0)
		{
			ft_putstr_fd("0x", fd);
			ft_putnbr_base_fd(vptr, "0123456789abcdef",
				fd);
		}
		else ft_putstr_fd("(nil)", fd);
	}
	else if (code == 'x')
		ft_putnbr_base_fd(va_arg(list, int), "0123456789abcdef", fd);
	else if (code == 'X')
		ft_putnbr_base_fd(va_arg(list, int), "0123456789ABCDEF", fd);
}

#include <stdio.h>

int	main(void)
{
	unsigned int	umax;
	char			*nptr;
	char			*string;

	ft_printf("I just wanted to say: %s%c%s%c%c%s%i%d\n", "Hello", ' ', "World",
		'!', ' ', "The year is: ", 0x14, 24);
	ft_printf("But my brain is 100%% sure it is still 2020\n");
	umax = 4294967295;
	ft_printf("This is int min: %i\n", -2147483648);
	string = "I am a String";
	printf("This is an adress: %p\n", string);
	nptr = 0;
	ft_printf("This is an adress: %p\n", string);
	ft_printf("This is a null pointer with %%p: %p\n", nptr);
	ft_printf("This is a null pointer with %%s: %s\n", nptr);
	ft_printf("This is %i as a lowercase hexadecimal number: %x\n", 123456789,
		123456789);
	ft_printf("This is %i as an uppercase hexadecimal number: %X\n", 123456789,
		123456789);
	ft_printf("This is unsigned int max: %u\n", umax);
}
