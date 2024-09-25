/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:30:17 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 21:38:35 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if the input character is a specifier or
	% (in contrast to a flag)
 *
 * @param c The character that needs to be checked
 *
 * @return 1 - If the character is a specifier (or %)
 *
 * 			0 - If the charater is no a specifier (or %)
 */

int	ft_is_specifier(char c)
{
	if (c == 's' || c == 'p' || c == 'c')
		return (1);
	if (c == 'd' || c == 'i' || c == 'u')
		return (2);
	if (c == 'x' || c == 'X' || c == '%')
		return (3);
	return (0);
}
