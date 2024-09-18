#include "libft.h"

int	ft_puthexaident_fd(char code, int fd)
{
	if (code == 'x')
		write(fd, "0x", 2);
	else if (code == 'X')
		write(fd, "0X", 2);
	return (2);
}