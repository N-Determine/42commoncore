/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 15:33:23 by adeters          ###   ########.fr       */
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
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	new_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	ft_free_all(char **arr, t_stacks *stacks)
{
	int	index;

	index = stacks->len;
	if (stacks->str_in && index)
	{
		while (index >= 0)
		{
			free(arr[index]);
			index--;
		}
		free(arr);
	}
}

int	check_single_str(int ac, char **av, t_fails *fails)
{
	if (check_args(ac, av, fails))
		return (print_errors_args(ARGS, fails), 1);
	else
		return (0);
}

char	**new_av_maker(char *input, int *ac, int *str_in)
{
	char	**new_av;

	new_av = ft_split(input, ' ');
	if (!new_av)
		return (print_errors(MAL), NULL);
	*ac = new_count(new_av);
	*str_in = 1;
	return (new_av);
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
		av = new_av_maker(av[1], &ac, &stacks.str_in);
	if (!av)
		return (1);
	if (check_args(ac, av, &fails))
		return (ft_free_all(av, &stacks), print_errors_args(ARGS, &fails), 1);
	if (fill_stacks(ac, av, &stacks, &fails))
		return (ft_free_all(av, &stacks), 1);
	if (is_sorted(stacks.stack_a))
		return (ft_free_all(av, &stacks), free(stacks.sorted),
			clear_stack_a(&stacks), 0);
	push_swap(&stacks);
	clear_stack_a(&stacks);
	return (free(stacks.sorted), ft_free_all(av, &stacks), 0);
}
