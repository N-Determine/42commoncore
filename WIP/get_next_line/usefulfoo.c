#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Check if there is a newline within a string str
 * 
 * @return 1 - if there is a newline 
 * 
 * 			0 - if not
 */
int	ft_check_nl(char *str)
{
	int	index;

	index = -1;
	while (index++ < BUFFER_SIZE && str[index])
	{
		if (str[index] == '\n')
			return (1);
	}
	return (0);
}

/**
 * @brief Copies from src into dest until it finds char c (including c)
 * 
 * @attention This will not work if the src does not have char c in it and will 
 * segfaulting behaviour. Only use after verifying that char c is contained in str.
 * There are now bound checks if dest is big enough
 * 
 * @details Use with char = '\0' for normal strings and char = '\n' to copy the final string
 */
char	*ft_copy_until_char(char *dest, char *src, char c)
{
	int index;

	index = 0;
	while (src[index] != c)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = src[index];
	return (dest);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

/* int main(void)
{
	char dest[100];
	char *src = "Hello \nWorld!";
	ft_copy_until_char(dest, src, '\n');
	int i = 0;
	while (i < 7)
	{
		printf("%c\n", dest[i]);
		i++;
	}
} */

/* int main(void)
{
	char *ptr = ft_calloc(5, 5);
	printf("%s\n", ptr);
} */