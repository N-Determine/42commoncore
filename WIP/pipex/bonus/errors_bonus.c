/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:36 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:21:39 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	p_err(int code)
{
	if (code == USAGE)
		ft_fprintf(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n");
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

int	p_err_arg(int code, const char *arg)
{
	if (code == ACCESS)
		ft_fprintf(2, "shell: command not found: %s\n", arg);
	if (code == PERM)
		ft_fprintf(2, "shell: permission denied: %s\n", arg);
	return (code);
}
