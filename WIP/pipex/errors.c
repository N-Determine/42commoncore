/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:36 by adeters           #+#    #+#             */
/*   Updated: 2025/01/12 15:06:04 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_errors(int code)
{
	if (code == ACCESS)
		ft_fprintf(2, "shell: command not found: \n");
	if (code == PERM)
		ft_fprintf(2, "shell: permission denied: \n");
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
	if (code == LIMIT)
		ft_fprintf(2, "Two many pipes used (Limit: %i)\n", FD_LIMIT);
	if (code == EXEC)
		ft_fprintf(2, "Execve function failed to execute\n");
	return (code);
}
