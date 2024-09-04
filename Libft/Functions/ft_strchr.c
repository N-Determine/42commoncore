char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		return (char *)&s[i];
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "Hello WorlWd!";
	printf("%s\n", ft_strchr(s, 'W'));
	printf("%s\n", strchr(s, 'W'));
}*/