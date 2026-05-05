#include "push_swap.h"

// Chunk Based Sort
#include <math.h>

void	sort_medium(t_stacks *data)
{
	int	chunk;
	int	i;

	chunk = sqrt(data->a->size);
	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= i)
		{
			pb(data);
			rb(data);
			i++;
		}
		else if (data->a->top->index <= i + chunk)
		{
			pb(data);
			i++;
		}
		else
			ra(data);
	}
	while (data->b->size > 0)
	{
		int pos = find_max_pos(data->b);

		if (pos <= data->b->size / 2)
			while (pos-- > 0)
				rb(data);
		else
			while (pos++ < data->b->size)
				rrb(data);

		pa(data);
	}
}