/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:25:48 by adeters           #+#    #+#             */
/*   Updated: 2024/09/06 12:31:15 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		static_checkset(char c, char const *set);
int		static_trim_strlen(char const *s1, char const *set, int start);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		size;
	int		i;
	char	*ptr;

	start = 0;
	i = 0;
	while (static_checkset(s1[start], set))
		start++;
	size = static_trim_strlen(s1, set, start) + 1;
	ptr = (char *) malloc(size * sizeof(char));
	if (ptr == 0)
		return (0);
	while (i < (size - 1))
	{
		ptr[i] = s1[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	static_checkset(char c, char const *set)
{
	int	i;
	int	check;

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

int	static_trim_strlen(char const *s1, char const *set, int start)
{
	int	end;
	int	i;

	end = start;
	i = 0;
	while (s1)
	{
		while (!static_checkset(s1[end], set) && s1[end])
			end++;
		i = 0;
		while (static_checkset(s1[end + i], set) && s1[end])
		{
			if (s1[end + i + 1] == '\0')
				return (end - start);
			i++;
		}
		end += i;
	}
	return (end - start);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = "--  .. World. - -";
	char *set = "- .";
	printf("%s\n", ft_strtrim(s, set));
}*/