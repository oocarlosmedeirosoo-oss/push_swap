/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:01:40 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:02 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	rotate(data->a);
	bench_stats->ra++;
	bench_stats->total_ops++;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	rotate(data->b);
	bench_stats->rb++;
	bench_stats->total_ops++;
	if (print)
		write(1, "rb\n", 3);
}

// Shift ra and rb at the same time.
void	rr(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	ra(data, print, bench_stats);
	rb(data, print, bench_stats);
	if (print)
		write(1, "rr\n", 3);
}
