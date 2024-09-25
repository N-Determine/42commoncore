/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:03:35 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 22:01:34 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct flag
{
	int	hexa_ident;
	int	plus_ident;
	int	space_ident;
}		t_bonus_flags;

int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putnbr_base_fd(long long nbr, char *base, int fd);
int		ft_putstr_fd_retbytes(char *str, int fd);
int		ft_count_bytes(int nbr);
int		ft_puthexas_fd(char code, va_list list, int fd);
int		ft_putchars_fd(char code, va_list list);
int		ft_putnumbers_fd(char code, va_list list, t_bonus_flags flag, int fd);
int		ft_puthexaident_fd(char code, int fd);
int		ft_printf(const char *str, ...);
int		ft_is_specifier(char c);
void	ft_init_flags(t_bonus_flags *flag);
void	ft_check_flags(t_bonus_flags *flag, char flag_code);

#endif