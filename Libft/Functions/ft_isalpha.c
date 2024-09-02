/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:53:03 by adeters           #+#    #+#             */
/*   Updated: 2024/09/02 15:53:30 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char c1 = 'A';
	char c2 = 'Q';
	char c3 = '?';
	
	printf("%i\n", ft_isalpha(c1));
	printf("%i\n", ft_isalpha(c2));
	printf("%i\n", ft_isalpha(c3));

}*/
