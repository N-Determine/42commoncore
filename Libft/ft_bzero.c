/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:39:38 by adeters           #+#    #+#             */
/*   Updated: 2024/09/08 16:11:47 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t		i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char s[20] = "Hello World!";
	ft_bzero(s, 4);
	printf("%s\n", s);
}*/