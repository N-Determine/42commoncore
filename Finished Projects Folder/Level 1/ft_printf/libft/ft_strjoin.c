/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:02:59 by adeters           #+#    #+#             */
/*   Updated: 2024/09/08 16:30:09 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	size = ft_strlen ((char *)s1) + ft_strlen ((char *)s2) + 1;
	ptr = (char *)malloc (size * sizeof(char));
	if (ptr == 0)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = " World!";
	printf("%s\n", ft_strjoin(s1, s2));
}*/
