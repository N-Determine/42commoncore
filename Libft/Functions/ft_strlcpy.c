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

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[size] = '\0';
	return (i);
}

#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dest1[10];
	char src1[15] = "Hellooooooo";
	char dest2[10];
	char src2[15] = "Hellooooooo";

	printf("%i\n", ft_strlcpy(dest1, src1, 11));
	printf("%s\n", src1);
	printf("%zu\n", strlcpy(dest2, src2, 11));
	printf("%s\n", src2);
}
