#include "push_swap.h"

// Insertion Sort
static void	rotate_to_top(t_stacks *data, int pos)
{
	int	size = data->a->size;

	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(data);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(data);
	}
}

void	sort_simple(t_stacks *data)
{
	int	pos;

	while (!is_sorted(data->a))
	{
		pos = find_min_pos(data->a);
		rotate_to_top(data, pos);
		pb(data);
	}
	while (data->b->size > 0)
		pa(data);
}
