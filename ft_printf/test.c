/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:09:04 by adeters           #+#    #+#             */
/*   Updated: 2024/09/15 14:44:37 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>


/**
 * @brief This function calculates the some of the num_args arguments
	after the first argument
 * @param num_args This is the amount of arguments included
 * @param ... This indicates a variable amount of other inputs
 * @return The sum of all the parameters
 */
int	sum(int num_args, ...);

int	sum(int num_args, ...)
{
	int		result;
	int		i;
	va_list	args;

	result = 0;
	i = 0;
	va_start(args, num_args);
	while (i < num_args)
	{
		result += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (result);
}
/* 
int	main(void)
{
	int	summe;

	summe = sum(4, 5, 3, 5, 6);
	printf("%i", summe);
} */


