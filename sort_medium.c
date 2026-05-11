/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:18:56 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 15:36:45 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int num)
{
	int	i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}

static void	sort_medium_helper(t_stacks *data, int print,
			t_bench_stats *bench_stats, int *chunk)
{
	int	i;

	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= i)
		{
			pb(data, print, bench_stats);
			rb(data, print, bench_stats);
			i++;
		}
		else if (data->a->top->index <= i + *chunk)
		{
			pb(data, print, bench_stats);
			i++;
		}
		else
			ra(data, print, bench_stats);
	}
}

void	sort_medium(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	int	chunk;
	int	pos;

	chunk = ft_sqrt(data->a->size);
	sort_medium_helper(data, print, bench_stats, &chunk);
	while (data->b->size > 0)
	{
		pos = find_max_pos(data->b);
		if (pos <= data->b->size / 2)
			while (pos-- > 0)
				rb(data, print, bench_stats);
		else
			while (pos++ < data->b->size)
				rrb(data, print, bench_stats);
		pa(data, print, bench_stats);
	}
}
