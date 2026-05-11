/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:18:56 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:25 by cbarbosa         ###   ########.fr       */
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
			t_bench_stats *bench, int *chunk)
{
	int	i;

	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= i)
		{
			pb(data, print, bench);
			rb(data, print, bench);
			i++;
		}
		else if (data->a->top->index <= i + *chunk)
		{
			pb(data, print, bench);
			i++;
		}
		else
			ra(data, print, bench);
	}
}

void	sort_medium(t_stacks *data, int print, t_bench_stats *bench)
{
	int	chunk;
	int	pos;

	bench->strategy = "Medium / O(n√n)";
	chunk = ft_sqrt(data->a->size);
	sort_medium_helper(data, print, bench, &chunk);
	while (data->b->size > 0)
	{
		pos = find_max_pos(data->b);
		if (pos <= data->b->size / 2)
			while (pos-- > 0)
				rb(data, print, bench);
		else
			while (pos++ < data->b->size)
				rrb(data, print, bench);
		pa(data, print, bench);
	}
}
