/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:42:06 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/06 20:42:07 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Insertion Sort
static void	rotate_to_top(t_stacks *data, int pos, int print, t_bench_stats *bench_stats)
{
	int	size = data->a->size;

	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			ra(data, print);
			bench_stats->ra++;
			bench_stats->total_ops++;
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			rra(data, print);
			bench_stats->rra++;
			bench_stats->total_ops++;
		}
	}
}

void	sort_simple(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	int	pos;
	while (!is_sorted(data->a))
	{
		pos = find_min_pos(data->a);
		rotate_to_top(data, pos, print, bench_stats);
		pb(data, print);
		bench_stats->pb++;
		bench_stats->total_ops++;
	}
	while (data->b->size > 0)
	{
		pa(data, print);
		bench_stats->pa++;
		bench_stats->total_ops++;
	}
}
