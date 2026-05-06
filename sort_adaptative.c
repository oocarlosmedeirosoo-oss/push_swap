/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:49:28 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/06 22:36:34 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_adaptive(t_stacks *data, int print, t_bench_stats *bench)
{
	float disorder;

	disorder = (float)bench->disorder / 10000;
	if (disorder < 0.2)
	{
	/* 	ft_printf("This one is simple\n"); */
		sort_simple(data, print, bench);
		bench->strategy = "Simple / O(n^2)";
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		/* ft_printf("This one is medium\n"); */
		sort_medium(data, print, bench);
		bench->strategy = "Medium / O(n√n)";
		
	}
	else
	{
	/* 	ft_printf("This one is complex\n"); */
		sort_complex(data, print, bench);
		bench->strategy = "Complex / O(n log n)";
	}
}
