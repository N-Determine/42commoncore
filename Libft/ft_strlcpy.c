/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:01:56 by adeters           #+#    #+#             */
/*   Updated: 2024/09/02 17:01:58 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (src[y])
		y++;
	if (size > 0)
	{
		while (i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (y);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dest1[10];
	char src1[20] = "worldHellooooooo";
	char dest2[10];
	char src2[20] = "worldHellooooooo";

	printf("The result of your function is:\n");
	printf("%zu\n", ft_strlcpy(dest1, src1, 10));
	printf("Original string: %s\n", src1);
	printf("Copied string: %s\n", dest1);
	printf("The result of the original function is:\n");
	printf("%zu\n", strlcpy(dest2, src2, 10));
	printf("Original String: %s\n", src2);
	printf("Copied String: %s\n", dest2);
}*/
