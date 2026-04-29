/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:45 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/29 20:27:41 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	sa(stack *a)
{
	stack i;


}

void	sb(stack *b)
{
	
}

void	ss(stack *a, stack *b)
{
	
}

 */


/* criar
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

adicionar a frente
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
adicionar atras
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

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

































/* 
// (swap a): Swap the first two elements at the top of stack a
void sa(stack **a)
{
	stack *i;

	if ((*a) && (*a)->next)
	{
		i = (*a)->next;
		if (i->next)
			(*a)->next = i->next;
		i->next = (*a);
		*a = i;
	}
}

// (swap b): Swap the first two elements at the top of stack b.
void sb(stack **b)
{
	stack *i;

	if ((*b) && (*b)->next)
	{
		i = (*b)->next;
		if (i->next)
			(*b)->next = i->next;
		i->next = (*b);
		*b = i;
	}
}

// Exec sa and sb at the same time.
void ss(stack **a, stack **b)
{
	sa(a);
	sb(b);
} */