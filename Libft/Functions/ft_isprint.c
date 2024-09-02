/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:47:10 by adeters           #+#    #+#             */
/*   Updated: 2024/09/02 16:47:13 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_isprint('A'));
	printf("%i\n", ft_isprint('0'));
	printf("%i\n", ft_isprint(' '));
	printf("%i\n", ft_isprint('\n'));
	printf("%i\n", ft_isprint('9'));
	printf("%i\n", ft_isprint('&'));
}*/
