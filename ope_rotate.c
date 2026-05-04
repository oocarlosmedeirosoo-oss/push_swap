/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:14:05 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/05/04 09:49:02 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (rotate a): Shift up all elements of stack a by one.
void	ra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		*a = (*a)->next;
		tmp = tmp->next;
		tmp->next = NULL;
	}
	(void)b;
}
// (rotate b): Shift up all elements of stack b by one.
void	rb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	(void)a;
	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		*b = (*b)->next;
		tmp = tmp->next;
		tmp->next = NULL;
	}
}

// (Rotate): ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
}
void	rra(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	
}

// (reverse rotate b): Shift down all elements of t_stack b by one
void	rrb(t_stack **b)
{
	t_stack *tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *b;
		*b = tmp->next;
		tmp->next = NULL;
	}
	
}
