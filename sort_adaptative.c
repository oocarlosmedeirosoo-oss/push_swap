/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:49:28 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 15:38:50 by mifranci         ###   ########.fr       */
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
		bench->strategy = "Simple / O(n^2)";
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		sort_medium(data, print, bench);
		bench->strategy = "Medium / O(n√n)";
	}
	else
	{
		sort_complex(data, print, bench);
		bench->strategy = "Complex / O(n log n)";
	}
}
