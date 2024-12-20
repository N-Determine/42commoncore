/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:25:47 by adeters           #+#    #+#             */
/*   Updated: 2024/09/13 13:39:41 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* 
#include <stdio.h>

int	main(void)
{
	char *text = "Hello ";
	char *text1 = "World!";
	t_list *new = ft_lstnew(text);
	t_list *lst = ft_lstnew(text1);
	ft_lstadd_front(&lst, new);
	printf("%p\n", (void *)new->next);
	printf("%p\n", lst);
} */