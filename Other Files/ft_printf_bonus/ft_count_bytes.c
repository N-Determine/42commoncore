/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:02:18 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 14:03:55 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_bytes(int nbr)
{
	int	chars;

	chars = 0;
	if (nbr <= 0)
		chars = 1;
	while (nbr)
	{
		nbr = nbr / 10;
		chars++;
	}
	return (chars);
}