/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:10:29 by adeters           #+#    #+#             */
/*   Updated: 2024/11/14 20:33:19 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper(' '));
	printf("%c\n", ft_toupper('?'));
	printf("%c\n", ft_toupper('2'));
}*/
