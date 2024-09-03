/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:07:41 by adeters           #+#    #+#             */
/*   Updated: 2024/09/03 12:07:44 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;

	if (size < i)
		return (j + size);
		
	
	// Check if size is big enough for appending anything
	if (i >= size) // if dst is longer than or equal to size it is not big enough
		return (i + j);
	//Concatenate until there is no more space left in dst (aka size-dst_len-NUL)

	while ((i + k) < (size - 1) && src[k])
	{
		dst[i + k] = src[k];
		k++;
	}
	// Nul Terminate the final string
	dst[i + k] = '\0';
		
	return (i + j);
}

#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char src1[10] = " World";
	char dst1[12] = "Hello";
	char src2[10] = " World";
	char dst2[12] = "Hello";
	
	printf("The result of your function is:\n");
	printf("Output %zu\n", ft_strlcat(dst1, src1, 1));
	printf("Final string: %s\n", dst1);
	printf("The result of the original function is:\n");
	printf("Output %zu\n", strlcat(dst2, src2, 1));
	printf("Final string: %s\n", dst2);
}
