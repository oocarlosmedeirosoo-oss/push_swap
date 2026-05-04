#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
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

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
t_stack	*ft_lstnew(void *data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
int	ft_lstsize(t_stack *lst)
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
