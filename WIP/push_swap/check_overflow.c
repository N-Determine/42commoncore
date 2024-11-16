/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:16:45 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 17:32:37 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow_digits(char *str)
{
	if (str[0] > 2 + '0')
		return (1);
	if (str[1] > 1 + '0')
		return (1);
	if (str[2] > 4 + '0')
		return (1);
	if (str[3] > 7 + '0')
		return (1);
	if (str[4] > 4 + '0')
		return (1);
	if (str[5] > 8 + '0')
		return (1);
	if (str[6] > 3 + '0')
		return (1);
	if (str[7] > 6 + '0')
		return (1);
	if (str[8] > 4 + '0')
		return (1);
	if (str[9] > 7 + '0')
		return (1);
	return (0);
}

static int	underflow_digits(char *str)
{
	if (str[1] > 2 + '0')
		return (-1);
	if (str[2] > 1 + '0')
		return (-1);
	if (str[3] > 4 + '0')
		return (-1);
	if (str[4] > 7 + '0')
		return (-1);
	if (str[5] > 4 + '0')
		return (-1);
	if (str[6] > 8 + '0')
		return (-1);
	if (str[7] > 3 + '0')
		return (-1);
	if (str[8] > 6 + '0')
		return (-1);
	if (str[9] > 4 + '0')
		return (-1);
	if (str[10] > 8 + '0')
		return (-1);
	return (0);
}

int	check_overflow(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 11 && str[0] == '-')
		return (0);
	if (len < 10)
		return (0);
	if (len > 11 && str[0] == '-')
		return (-1);
	else if (len > 10 && str[0] != '-')
		return (1);
	if (len == 11 && str[0] == '-')
		return (underflow_digits(str));
	if (len == 10 && str[0] != '-')
		return (overflow_digits(str));
	return (0);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char *str2 = "-2149483647"; // Should underflow
	char *str3 = "2147483648"; // Should overflow
	char *str = "2147483647"; // Should fit
	char *str1 = "-2147483648"; // Should fit
	char *str4 = "0";
	printf("Over/underflow for %s? -> %i\n", str2, check_overflow(str2));
	printf("Over/underflow for %s? -> %i\n", str3, check_overflow(str3));
	printf("Over/underflow for %s? -> %i\n", str, check_overflow(str));
	printf("Over/underflow for %s? -> %i\n", str1, check_overflow(str1));
	printf("Over/underflow for %s? -> %i\n", str4, check_overflow(str4));
}
*/
