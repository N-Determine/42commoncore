char	*ft_strrchr(const char *s, int c)
{
	int	i;
    char *ptr;

	i = 0;
    ptr = 0;
	while (s[i])
	{
		if (s[i] == c)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		ptr = (char *)&s[i];
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "Hello WorlWd!";
	printf("%s\n", ft_strrchr(s, 'W'));
	printf("%s\n", strrchr(s, 'W'));
}*/