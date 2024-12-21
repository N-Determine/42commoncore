/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:39:44 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 18:39:53 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_fails(t_fails *fails)
{
	fails->underflows = 0;
	fails->overflows = 0;
	fails->formats = 0;
	fails->duplicates = 0;
}
