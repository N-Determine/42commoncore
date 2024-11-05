/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:44:55 by adeters           #+#    #+#             */
/*   Updated: 2024/11/05 14:40:19 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"

//int		ft_strlen(char *str);
char	*get_next_line(int fd);
//char	*ft_strchr(const char *s, int c);
//char	*ft_calloc(size_t nmemb, size_t size);
//size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif