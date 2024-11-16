/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:16:45 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 18:10:38 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflow_digits(char *str)
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

int	underflow_digits(char *str)
{
	if (str[0] > 2 + '0')
		return (-1);
	if (str[1] > 1 + '0')
		return (-1);
	if (str[2] > 4 + '0')
		return (-1);
	if (str[3] > 7 + '0')
		return (-1);
	if (str[4] > 4 + '0')
		return (-1);
	if (str[5] > 8 + '0')
		return (-1);
	if (str[6] > 3 + '0')
		return (-1);
	if (str[7] > 6 + '0')
		return (-1);
	if (str[8] > 4 + '0')
		return (-1);
	if (str[9] > 8 + '0')
		return (-1);
	return (0);
}

char	*ignore_sign(char *str, int *sign)
{
	int i;

	i = 0;
	if (str[0] == '+')
	{
		*sign = 1;
		i++;
	}
	else if (str[0] == '-')
	{
		*sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (NULL);
	while (str[i] && str[i] == '0')
		i++;
	return (&str[i]);
}

int	check_overflow(char *str)
{
	int		len;
	int		sign;
	char	*new;

	new = ignore_sign(str, &sign);
	if (!new)
		return (-2);
	len = ft_strlen(new);
	if (len > 10 && sign == -1)
		return (-1);
	if (len > 10 && sign == 1)
		return (1);
	if (len < 9)
		return (0);
	if (len == 10 && sign == -1)
		return (underflow_digits(new));
	else if (len == 10)
		return (overflow_digits(new));
	return (0);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char *str3 = "2147483648"; // Should overflow
	char *str4 = "--0";
	char *str1 = "-0000000002147483648"; // Should fit
	char *str2 = "-000000000000000000000002149483647"; // Should underflow
	char *str = "2147483647"; // Should fit
	printf("Over/underflow for %s? -> %i\n", str3, check_overflow(str3)); fflush(stdout);
	printf("Over/underflow for %s? -> %i\n", str4, check_overflow(str4)); fflush(stdout);
	printf("Over/underflow for %s? -> %i\n", str1, check_overflow(str1)); fflush(stdout);
	printf("Over/underflow for %s? -> %i\n", str2, check_overflow(str2)); fflush(stdout);
	printf("Over/underflow for %s? -> %i\n", str, check_overflow(str)); fflush(stdout);
}
*/
