/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:32:49 by adeters           #+#    #+#             */
/*   Updated: 2024/12/15 17:43:51 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "minitalk.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server started. PID: %i\n", pid);
	while(true)
	{
		pause();
	}
}
