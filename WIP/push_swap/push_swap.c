/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 17:20:55 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char *str = "2147483647";
	char *str1 = "-2147483648";
	char *str2 = "-2149483647";
	char *str3 = "2147483648";
	char *str4 = "0";
	printf("Over/underflow for %s? -> %i\n", str, check_overflow(str));
	printf("Over/underflow for %s? -> %i\n", str1, check_overflow(str1));
	printf("Over/underflow for %s? -> %i\n", str2, check_overflow(str2));
	printf("Over/underflow for %s? -> %i\n", str3, check_overflow(str3));
	printf("Over/underflow for %s? -> %i\n", str4, check_overflow(str4));
}
