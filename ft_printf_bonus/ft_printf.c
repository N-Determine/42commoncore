/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:13:24 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 22:08:26 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>
#include <stdio.h>

static int	ft_var_printer(char code, va_list list, t_bonus_flags flag);
static int	ft_is_flag(char c);
static int	ft_print_by_flags(t_bonus_flags flag, char code, va_list list,
				int bytes_written);
static int	ft_save_lines(const char *str, int *i, int bytes_written,
				va_list args);

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
		bytes_written = ft_save_lines(str, &i, bytes_written, args);
	va_end(args);
	return (bytes_written);
}

static int	ft_is_flag(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '#' || c == ' ' || c == '+')
		return (1);
	else if (c == '.' || c == '-')
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
static int	ft_var_printer(char code, va_list list, t_bonus_flags flag)
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
		return (ft_putnumbers_fd(code, list, flag, 1));
	else if (code == 'p' || code == 'x' || code == 'X')
		return (ft_puthexas_fd(code, list, 1));
	return (-1);
}

static int	ft_print_by_flags(t_bonus_flags flag, char code, va_list list,
		int bytes_written)
{
	if ((code == 'x' || code == 'X') && flag.hexa_ident == 1)
	{
		ft_puthexaident_fd(code, 1);
		bytes_written += ft_var_printer(code, list, flag) + 2;
	}
	else if ((code == 'd' || code == 'i') && flag.plus_ident == 1)
		bytes_written += ft_var_printer(code, list, flag);
	else if (ft_is_specifier(code) == 2 && flag.space_ident == 1)
		bytes_written += ft_var_printer(code, list, flag);
	else
		bytes_written += ft_var_printer(code, list, flag);
	return (bytes_written);
}

static int	ft_save_lines(const char *str, int *i, int bytes_written,
		va_list args)
{
	int				a;
	t_bonus_flags	flag;

	a = *i;
	if (str[a] == '%')
	{
		a++;
		ft_init_flags(&flag);
		while (str[a] && !ft_is_specifier(str[a]) && ft_is_flag(str[a]))
			ft_check_flags(&flag, str[a++]);
		bytes_written = ft_print_by_flags(flag, str[a++], args, bytes_written);
	}
	if (str[a] && str[a] != '%')
	{
		write(1, &str[a], 1);
		bytes_written++;
		a++;
	}
	*i = a;
	return (bytes_written);
}
/* 
#include <stdio.h>

int	main(void)
{
	unsigned int umax;
	char *nptr;
	char *string;
	int check;

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
	ft_printf("This is %i as a lowercase hexadecimal number: %x\n", -2147483648,
		-2147483648);
	ft_printf("This is %i as an uppercase hexadecimal number: %X\n", 123456789,
		123456789);
	ft_printf("This is unsigned int max: %u\n", umax);
	check = ft_printf("%p\n", LONG_MAX);
	ft_printf("%i\n", check);
	ft_printf("%x\n", 120);
	ft_printf("%#x\n", 120);
	ft_printf("%+i\n", 120);
	ft_printf("% i\n", -120);
	printf("% i\n", -120);
} */