/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:49:28 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:20 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stacks *data, int print, t_bench_stats *bench)
{
	float	disorder;

	disorder = (float)bench->disorder / 10000;
	if (disorder < 0.2)
	{
		sort_simple(data, print, bench);
		bench->strategy = "Adaptive / O(n^2)";
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		sort_medium(data, print, bench);
		bench->strategy = "Adaptive / O(n√n)";
	}
	else
	{
		sort_complex(data, print, bench);
		bench->strategy = "Adaptive / O(n log n)";
	}
}
