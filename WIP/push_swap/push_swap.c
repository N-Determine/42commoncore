/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 14:38:46 by adeters          ###   ########.fr       */
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

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	new_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;
	int			str_in;

	str_in = 0;
	if (ac < 2)
		return (0);
	if (ac == 2 && !ft_isdigit_str(av[1]))
		return (0);
	if (ac > 2 && ft_isdigit_str(av[1]))
		return (print_errors(USAGE), 1);
	else if (ac == 2 && str_splitable(av[1]))
		return (print_errors(SPLIT), 1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = new_count(av);
		str_in = 1;
	}
	if (check_args(ac, av, &fails))
		return (print_errors_args(ARGS, &fails), 1); // free av
	if (fill_stacks(ac, av, &stacks, &fails, str_in))
		return (1); // free av and add error message
	if (is_sorted(stacks.stack_a))
		return (free(stacks.sorted), clear_stack_a(&stacks), 0); // free av
	stacks.stack_b = NULL;
	push_swap(&stacks);
	clear_stack_a(&stacks);
	free(stacks.sorted);
	// free av
}
