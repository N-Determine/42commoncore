/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:52 by adeters           #+#    #+#             */
/*   Updated: 2024/09/08 12:05:37 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	test_func(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = 'A';
}

#include <stdio.h>

int	main(void)
{
	char	str[20] = "hello world!";
	ft_strteri(str, test_func);
	printf("%s\n", str);
}*/