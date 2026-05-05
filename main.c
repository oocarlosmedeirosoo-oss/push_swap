#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*data;

	data = parse_args(argc, argv);
	if (!data)
		return (1);
	if (is_sorted(data->a))
	{
		data_free(data);
		return (0);
	}
	assign_indices(data->a);
	sort_complex(data);
	data_free(data);
	return (0);
}