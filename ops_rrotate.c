/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:01:17 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:05 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	reverse_rotate(data->a);
	bench_stats->rra++;
	bench_stats->total_ops++;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	reverse_rotate(data->b);
	bench_stats->rrb++;
	bench_stats->total_ops++;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	rra(data, print, bench_stats);
	rrb(data, print, bench_stats);
	if (print)
		write(1, "rrr\n", 4);
}
