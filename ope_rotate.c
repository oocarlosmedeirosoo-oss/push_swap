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

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
