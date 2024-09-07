/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:08:58 by adeters           #+#    #+#             */
/*   Updated: 2024/09/07 17:04:36 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char const	*ptr;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen((char *)s);
	ptr = malloc(len + 1);
	if (ptr == 0)
		return (0);
	while (i < len)
	{
		ptr[i] = *f(i, s[i]);
		i++;
	}
	return ((char *)ptr);
}