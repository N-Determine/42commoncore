/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 18:51:55 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_fails	fails;

	if (ac < 2)
		return (print_errors(USAGE), 1);
	if (check_args(ac, av, &fails))
		return (print_errors(ARGS), 1);
}
