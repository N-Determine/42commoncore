/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:10:57 by adeters           #+#    #+#             */
/*   Updated: 2024/09/05 12:11:37 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "teste";
	char *ptr = ft_strchr(s, 1);
	char *ptr1 = strchr(s, 't' + 256);
	//printf("%s\n", ptr);
	printf("%s\n", (char *)0);
	printf("%s\n", ptr1);
}*/