/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:36 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 16:11:05 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_errors(int code)
{
	if (code == USAGE)
		ft_fprintf(2, "Usage: ./pipex infile command command outfile\n");
	if (code == PATHS)
		ft_fprintf(2, "PATH could not be loaded\n");
	if (code == PIPE)
		ft_fprintf(2, "Pipe function failed to execute\n");
	if (code == FORK)
		ft_fprintf(2, "Fork function failed to execute\n");
	if (code == OPEN)
		ft_fprintf(2, "Open function failed to execute\n");
	return (code);
}
