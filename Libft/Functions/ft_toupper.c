int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper(' '));
	printf("%c\n", ft_toupper('?'));
	printf("%c\n", ft_toupper('2'));
}*/
