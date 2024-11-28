/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 15:57:49 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_splitable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;

	stacks.str_in = 0;
	if (ac < 2)
		return (0);
	if (ac > 2 && !ft_isdigit_str(av[1]))
		return (print_errors(USAGE), 1);
	if (ac == 2 && ft_isdigit_str(av[1]))
		return (check_single_str(ac, av, &fails));
	else if (ac == 2 && str_splitable(av[1]))
		return (print_errors(SPLIT), 1);
	else if (ac == 2)
		av = new_av_maker(av[1], &ac, &stacks);
	if (!av)
		return (1);
	if (check_args(ac, av, &fails))
		return (ft_free_all(av, &stacks), print_errors_args(ARGS, &fails), 1);
	if (fill_stacks(ac, av, &stacks, &fails))
		return (ft_free_all(av, &stacks), 1);
	if (is_sorted(stacks.stack_a))
		return (ft_free_all(av, &stacks), free(stacks.sorted),
			clear_stack_a(&stacks), 0);
	return (push_swap(&stacks), clear_stack_a(&stacks), free(stacks.sorted),
		ft_free_all(av, &stacks), 0);
}
