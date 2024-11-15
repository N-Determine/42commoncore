/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:02:23 by adeters           #+#    #+#             */
/*   Updated: 2024/11/15 21:02:46 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_errors(int code)
{
	ft_fprintf(2, "Error\n");
	if (code == INT_OVERFLOW)
		ft_fprintf(2, "This value creates and integer overflow\n");
}
