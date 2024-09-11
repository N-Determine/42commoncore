#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == 0)
		return (0);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}

#include <stdio.h>

int	main(void)
{
	char *content = "Hello World!";
	t_list *node1 = ft_lstnew((void *)content);
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node1->next);
	free(node1);
}