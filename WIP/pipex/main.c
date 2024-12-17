/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2024/12/17 15:35:10 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, const char **av, const char **env)
{
	char	**paths;
	int		acc;

	paths = get_paths(env);
	if (!paths)
		return (print_errors(PATHS));
	acc = check_access(paths, "ls");
	ft_printf("Check: %i\n", acc);
	ft_free_list(paths);
}
