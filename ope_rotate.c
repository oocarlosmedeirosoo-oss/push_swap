/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:14:05 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/30 18:43:38 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* // (rotate a): Shift up all elements of stack a by one.
void	ra(stack **a)
{
	stack	*tmp;

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
}

// (rotate b): Shift up all elements of stack b by one.
void	rb(stack **b)
{
	stack	*tmp;

	if (*b && (*b)->next)
	{
		printf("chegou\n");
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		*b = (*b)->next;
		tmp = tmp->next;
		tmp->next = NULL;
	}
}

// ra and rb at the same time.
void	rr(stack **a, stack **b)
{
	ra(a);
	rb(b);
}

// (reverse rotate a): Shift down all elements of stack a by one.
void	rra(stack **a)
{
	stack *tmp;

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

// (reverse rotate b): Shift down all elements of stack b by one
void	rrb(stack **b)
{
	stack *tmp;

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

// rra and rrb at the same time.
void	rrr(stack **a, stack **b)
{
	rra(a);
	rrb(b);
}

 */