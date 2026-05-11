/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:41:57 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 20:08:17 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = 0;
	total = (stack->size * (stack->size - 1) / 2);
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total);
}
/*
Para uma stack: 1 2 3 eles definem pares por (1,2) (1,3) (2,3) e nao (1,2)(2,3)
Resultado entre 0.0 (ordenada) e 1.0 (nao ordenado).
*/
