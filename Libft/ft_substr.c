/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:07:29 by adeters           #+#    #+#             */
/*   Updated: 2024/09/08 16:30:43 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = (size_t)ft_strlen(s);
	if (start > (s_len + 1))
	{
		ptr = (char *)malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	else
		ptr = (char *)malloc((s_len + 1 - start) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (i < len && (start + i) < s_len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* 
#include <stdio.h>

int	main(void)
{
	char *s = "Ernährungsexperte";
	char *s2 = ft_substr(s, 10, 3);
	if (s2 != 0)
		printf("%s\n", s2);
	free(s2);
	printf("%s\n", ft_substr("hola", 4294967295,0));
}  */