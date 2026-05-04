/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:45 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/05/04 13:45:19 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements at the top of stack a. - Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	t_stack *temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}
// Swap the first two elements at the top of stack b - Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
	t_stack *temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
}
// Swap sa and sb at the same time.
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
// Take the first element at the top of b and put it at the top of a. - Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	printf("pa\n");
}
// Take the first element at the top of a and put it at the top of b. - Do nothing if b is empty.
void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	printf("pb\n");
}


