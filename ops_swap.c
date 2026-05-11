/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:00:39 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:08 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	swap_top(data->a);
	bench_stats->sa++;
	bench_stats->total_ops++;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	swap_top(data->b);
	bench_stats->sb++;
	bench_stats->total_ops++;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	sa(data, print, bench_stats);
	sb(data, print, bench_stats);
	if (print)
		write(1, "ss\n", 3);
}
