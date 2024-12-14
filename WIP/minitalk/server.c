#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	pid_t pid; 
	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
}

