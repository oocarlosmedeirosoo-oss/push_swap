/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:14:03 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/29 16:14:26 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (push a): Take the first element at the top of b and put it at the top of a.
void	pa(stack **a, stack **b)
{
	stack	*tmp;

	if (*b)
	{
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		if (tmp)
			(*a)->next = tmp;
		else
			(*a)->next = NULL;
	}
}

// (push b): Take the first element at the top of a and put it at the top of b.
void	pb(stack **a, stack **b)
{
	stack	*tmp;

	if (*a)
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->next;
		if (tmp)
			(*b)->next = tmp;
		else
			(*b)->next = NULL;
	}
}