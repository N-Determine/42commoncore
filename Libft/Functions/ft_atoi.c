int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nmb;
	int	i;

	sign = 1;
	nmb = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == 32 || nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nmb = nmb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nmb * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *str = "    'EOF'";
	printf("%i\n", ft_atoi(str));
	printf("%i\n", atoi(str));
}*/
