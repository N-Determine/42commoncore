/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:31:53 by adeters           #+#    #+#             */
/*   Updated: 2024/09/02 16:31:55 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_isascii('a'));
	printf("%i\n", ft_isascii('\0'));
	printf("%i\n", ft_isascii('?'));
	printf("%i\n", ft_isascii((char)127));
	printf("%i\n", ft_isascii((char)155));
}*/
