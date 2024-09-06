#include <stdlib.h>

// function to check if a character is part of a set
int		static_checkset(char c, char const *set);
int 	static_trim_strlen(char const *s1, char const *set, int start);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	//int	end;
	int	len;
	//int	i;
	char	*ptr;

	start = 0;
	// Find the index of the start of the trimmed string
	while (static_checkset(s1[start], set))
		start++;
	// Find the length of the trimmed string
	len = static_trim_strlen(s1, set, start);







	return (ptr);
}

int		static_checkset(char c, char const *set)
{
	int	i;
	int check;

	i = 0;
	check = 0;
	while (set[i])
	{
		if (c == set[i])
			check = 1;
		i++;
	}
	return (check);
}

int static_trim_strlen(char const *s1, char const *set, int start)
{
	int end;
	int i;

	end = start;
	i = 0;
	// Find the index of the end of the trimmed string
	while (s1)
	{
		// increase index as long as checkset is not true
		while (!static_checkset(s1[end], set) && s1[end])
			end++;
		// look for the NUL Byte, if not found before !checkset, start again 
		i = 0;
		while (static_checkset(s1[end + i], set) && s1[end])
		{
			if (s1[end + i + 1] == '\0')
				return (end - start);
			i++;
		}
		end += i;
	}

}

#include <stdio.h>

int	main(void)
{
	char *s = "--  .. World. - -";
	char *set = "- .";
	printf("%s\n", ft_strtrim(s, set));
}