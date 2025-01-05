/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:36 by adeters           #+#    #+#             */
/*   Updated: 2025/01/05 13:17:23 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_errors(int code)
{
	if (code == PATHS)
		ft_fprintf(2, "PATH could not be loaded\n");
	if (code == USAGE)
		ft_fprintf(2, "Usage: ./pipex infile command command outfile\n");
	return (code);
}
