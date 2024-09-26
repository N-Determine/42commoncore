/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:44:29 by adeters           #+#    #+#             */
/*   Updated: 2024/09/26 11:17:57 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


/* char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
} */






/* 

int check_nl = 0;

while (check_nl == 0)
{
	check_nl = foo_that_makes_nodes;
	i++;
}

int space_to_allocate = check_nl + i + 1;


foo_that_makes_nodes
// Fuction returns position of where the \n was found or 0 if its not in there

// Read into a node of a linked list
	// Check if it contains a \n character
		// If it doesn't: Make a new node
		// Else stop


		


foo_that_copies_from_lst_to_allocated_space()

free lst

return string

 */
#include <stdio.h>

int	make_node(int fd)
{
	t_list	*lst;
	int		i = 0;
	int		j = 0;
	int		index = 0;
	char 	*ptr;
	char	buffer[BUFFER_SIZE];

	lst = malloc(sizeof(t_list *));
	if (!lst)
		return (-1);
	ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ptr)
		return (-1); 
	read(fd, buffer, BUFFER_SIZE);
	while(j < BUFFER_SIZE)
	{
		ptr[j] = buffer[j];
		j++;
	}
	ptr[BUFFER_SIZE] = '\0';
	lst->content = ptr;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

		




/* 
int	main(void)
{
	int fd = open("text.txt", O_RDWR);
	printf("%i\n", make_node(fd));
} */