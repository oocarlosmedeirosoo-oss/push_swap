#include "push_swap.h"

// Radix Sort
void	sort_complex(t_stacks *data)
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
				pb(data);
			else
				ra(data);
			j++;
		}
		while (data->b->size > 0)
			pa(data);
		i++;
	}
}
