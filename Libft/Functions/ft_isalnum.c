/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:22:39 by adeters           #+#    #+#             */
/*   Updated: 2024/09/02 16:22:45 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char c1 = 'A';
	char c2 = 'f';
	char c3 = '0';
	char c4 = '8';
	char c5 = ' ';
	char c6 = '{';
	
	printf("%i\n", ft_isalnum(c1));
	printf("%i\n", ft_isalnum(c2));
	printf("%i\n", ft_isalnum(c3));
	printf("%i\n", ft_isalnum(c4));
	printf("%i\n", ft_isalnum(c5));
	printf("%i\n", ft_isalnum(c6));
}*/
