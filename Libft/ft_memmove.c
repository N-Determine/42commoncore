/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:12:53 by adeters           #+#    #+#             */
/*   Updated: 2024/09/07 14:34:43 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	int				i;

	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest > src)
	{
		while (i <= n)
		{
			dest_ptr[(n - 1) - i] = src_ptr[(n - 1) - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest[20] = "HELLO!!!!";
	char src[20] = "Gfrast";
	printf("%s\n", (char *)ft_memmove(dest + 3, dest, 6));
	char dest1[20] = "HELLO!!!!";
	char src1[20] = "Gfrast";
	printf("%s\n", (char *)memmove(dest1 + 3, dest1, 6));
}*/