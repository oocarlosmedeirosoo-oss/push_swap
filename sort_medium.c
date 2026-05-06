#include "push_swap.h"

// Chunk Based Sort
#include <math.h>

void	sort_medium(t_stacks *data, int print, t_bench_stats *bench_stats)
{
	int	chunk;
	int	i;

	chunk = sqrt(data->a->size);
	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= i)
		{
			pb(data, print);
			bench_stats->pb++;
			bench_stats->total_ops++;
			rb(data, print);
			bench_stats->rb++;
			bench_stats->total_ops++;
			i++;
		}
		else if (data->a->top->index <= i + chunk)
		{
			pb(data, print);
			bench_stats->pb++;
			i++;
		}
		else
		{
			ra(data, print);
			bench_stats->ra++;
			bench_stats->total_ops++;
		}
	}
	while (data->b->size > 0)
	{
		int pos = find_max_pos(data->b);

		if (pos <= data->b->size / 2)
			while (pos-- > 0)
			{
				rb(data, print);
				bench_stats->rb++;
				bench_stats->total_ops++;
			}
		else
			while (pos++ < data->b->size)
			{
				rrb(data, print);
				bench_stats->rrb++;
				bench_stats->total_ops++;
			}
		pa(data, print);
		bench_stats->pa++;
		bench_stats->total_ops++;
	}
}
