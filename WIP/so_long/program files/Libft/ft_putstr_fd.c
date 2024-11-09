/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:18:03 by adeters           #+#    #+#             */
/*   Updated: 2024/11/09 22:51:31 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string ’s’ to the given file
descriptor 'fd'.
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write (fd, s, len);
}
/*
int	main(void)
{
	char *str = "Hey du gfrast!";
	ft_putstr_fd(str, 1);
}*/