#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = "Ernährungsexperte";
	printf("%s\n", ft_substr(s, 10, 3));
}*/