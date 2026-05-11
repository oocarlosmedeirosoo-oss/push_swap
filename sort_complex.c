/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:38:04 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 15:38:05 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = data->a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((data->a->top->index >> i) & 1) == 0)
				pb(data, print, bench_stats);
			else
				ra(data, print, bench_stats);
			j++;
		}
		while (data->b->size > 0)
			pa(data, print, bench_stats);
		i++;
	}
}
