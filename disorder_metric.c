/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_chunk_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:49 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/29 16:13:51 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// You must measure the disorder before doing any moves.
static int	ft_lstsize(t_stack *lst)
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
float	ft_disorder_metric(t_stack *a)
{
	float	mistakes;
	float	pairs;
	size_t	len_stack;
	t_stack *i;
	t_stack *j;

	mistakes = 0;
	pairs = 0;
	len_stack = ft_lstsize(a);
	if (len_stack < 2)
		return (0.0);
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0);
	printf("total_pairs = %0.2f\n", pairs);
	printf("mistakes = %0.2f\n", mistakes);
	return (mistakes / pairs);
	
}

/*
In this subject, disorder is a number between 0 and 1 that tells how far your initial
stack a is from being sorted.

É um nuemro entre 0 <--> 1

If the numbers are already in the right order, the disorder is 0.

If they are in the worst possible order, the disorder is 1.

Anything in between means your stack is partly sorted, but still messy.

To calculate it, you can think of looking at all the possible pairs of numbers in the stack.

Each time a bigger number appears before a smaller one, that pair counts as a mistake.

The more mistakes you have, the closer the disorder is to 1.
*\