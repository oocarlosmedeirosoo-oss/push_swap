#include "push_swap.h"

void	sort_adaptive(t_stacks *data)
{
	double	d;

	d = compute_disorder(data->a);
	if (d < 0.2)
		sort_simple(data);
	else if (d < 0.5)
		sort_medium(data);
	else
		sort_complex(data);
}
