/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:13:24 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 14:50:34 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static int	ft_is_specifier(char c);
static int	ft_var_printer(char code, va_list list);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		bytes_written;
	va_list	args;

	i = 0;
	bytes_written = 0;
	if (str == 0)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_is_specifier(str[i + 1]))
		{
			bytes_written += ft_var_printer(str[i + 1], args);
			i += 2;
		}
		if (str[i] && str[i] != '%')
		{
			write(1, &str[i], 1);
			bytes_written++;
			i++;
		}
	}
	va_end(args);
	return (bytes_written);
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
	if (c == 's' || c == 'p' || c == 'c')
		return (1);
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

/**
 * @brief Prints the content of the list using a differnt function to print it
 * depending of the type of content it contains
 *
 * @param code The specifier that decides what function needs to be used to
 * print the content
 * @param list The pointer to the va	_list in which the content
 * needs to be printed
 */
static int	ft_var_printer(char code, va_list list)
{
	char	*ptr;

	ptr = 0;
	if (code == 's')
	{
		ptr = va_arg(list, char *);
		if (ptr != 0)
			return (ft_putstr_fd_retbytes(ptr, 1));
		else
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
	}
	else if (code == 'c' || code == '%')
		return (ft_putchars_fd(code, list));
	else if (code == 'i' || code == 'd' || code == 'u')
		return (ft_putnumbers_fd(code, list, 1));
	else if (code == 'p' || code == 'x' || code == 'X')
		return (ft_puthexas_fd(code, list, 1));
	return (-1);
}
/* 
#include <stdio.h>

int	main(void)
{
	unsigned int	umax;
	char			*nptr;
	char			*string;
	int				check;

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
	ft_printf("This is %i as a lowercase hexadecimal number: %x\n", -2147483648, -2147483648);
	ft_printf("This is %i as an uppercase hexadecimal number: %X\n", 123456789,
		123456789);
	ft_printf("This is unsigned int max: %u\n", umax);
	check = ft_printf("%p", LONG_MAX);
	ft_printf("%i\n", check);
} */