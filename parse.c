#include "push_swap.h"

t_stacks	*parse_args(int argc, char **argv)
{
	t_stacks	*data;
	int			value;
	t_node		*new;

	if (argc < 2)
		return (NULL);
	data = malloc(sizeof(t_stacks));
	if (!data)
		return (NULL);
	data->a = stack_new();
	data->b = stack_new();
	if (!data->a || !data->b)
		return (ft_error(data), NULL);
	while (*argv)
	{
		if (!ft_atoi_safe(*argv++, &value))
			return (ft_error(data), NULL);
		if (has_duplicate(data->a, value))
			return (ft_error(data), NULL);
		new = node_new(value);
		if (!new)
			return (ft_error(data), NULL);
		stack_addback(data->a, new);
	}
	return (data);
}

// Imprime "Error\n" em stderr, liberta tudo e sai.
void	ft_error(t_stacks *data)
{
	data_free(data);
	write(2, "Error\n", 6);
	exit(1);
}

/*
Errors include, for example:
Arguments that are not integers
Integers outside the valid range
Duplicate values.
*/