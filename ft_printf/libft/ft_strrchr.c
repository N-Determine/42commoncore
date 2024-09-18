/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:11:03 by adeters           #+#    #+#             */
/*   Updated: 2024/09/05 12:12:28 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	c = c % 256;
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