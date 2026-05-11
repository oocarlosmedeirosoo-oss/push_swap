/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:42:06 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:28 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stacks *data, int pos, int print,
			t_bench_stats *bench_stats)
{
	int	size;

	size = data->a->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			ra(data, print, bench_stats);
			bench_stats->ra++;
			bench_stats->total_ops++;
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			rra(data, print, bench_stats);
			bench_stats->rra++;
			bench_stats->total_ops++;
		}
	}
}

void	sort_simple(t_stacks *data, int print, t_bench_stats *bench)
{
	int	pos;

	bench->strategy = "Simple / O(n^2)";
	while (!is_sorted(data->a))
	{
		pos = find_min_pos(data->a);
		rotate_to_top(data, pos, print, bench);
		pb(data, print, bench);
		bench->pb++;
		bench->total_ops++;
	}
	while (data->b->size > 0)
	{
		pa(data, print, bench);
		bench->pa++;
		bench->total_ops++;
	}
}
