/**
* Lets make the most simple printf possible as a first test
*/

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_is_specifier(char c);

static void	ft_var_printer(char code, va_list list)
{
	if (code == 's')
		ft_putstr_fd(va_arg(list, char *), 1);
	else if (code == 'c')
		ft_putchar_fd((char)va_arg(list, int), 1);
	else if (code == 'i' || code == 'd')
		ft_putnbr_fd(va_arg(list, int), 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

	i = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%' && ft_is_specifier(str[i+1]))
		{
			ft_var_printer(str[i+1], args);
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


int	main(void)
{
	ft_printf("I just wanted to say: %s%c%s%c%c%s%i%d\n", "Hello", ' ', "World", '!', ' ',"The year is: ", 20, 24);
}