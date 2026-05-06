#include "push_swap.h"

// Radix Sort
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
			{
				pb(data, print);
				bench_stats->pb++;
				bench_stats->total_ops++;
			}
			else
			{
				ra(data, print);
				bench_stats->ra++;
				bench_stats->total_ops++;
			}
			j++;
		}
		while (data->b->size > 0)
		{
			pa(data, print);
			bench_stats->pa++;
			bench_stats->total_ops++;
		}
		i++;
	}
}
