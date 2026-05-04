#include "push_swap.h"


void add_back(t_stack **head, const char *data)
{
	t_stack	*node;
	t_stack	*i;

	node = malloc(sizeof(*node));
	node->data = ft_atoi(data);
	node->next = NULL;
	if (*head)
	{
		i = *head;
		while (i->next)
			i = i->next;
		i->next = node;
	}
	else
		*head = node;
}

size_t	ft_lstsize(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
