/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43:19 by adeters           #+#    #+#             */
/*   Updated: 2024/09/06 20:20:44 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_bytes(int n);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		bytes;
	int		i;
	int		check_pos;

	i = 0;
	bytes = ft_count_bytes(n);
	check_pos = 2;
	ptr = (char *)malloc (bytes * sizeof(char));
	if (ptr == 0)
		return (0);
	if (n == -2147483648)
	{
		ptr = "-2147483648";
		return (ptr);
	}
	if (n < 0)
	{
		n = n * (-1);
		ptr[0] = '-';
		check_pos = 1;
		i = 1;
	}
	ptr[bytes - 1] = '\0';
	while (i < (bytes - 1))
	{
		ptr[bytes - check_pos - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (ptr);
}

static int	ft_count_bytes(int n)
{
	int	digits;
	int	sign;

	digits = 1;
	if (n <= 0)
		digits = 2;
	while (n)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa(-2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(42));
}