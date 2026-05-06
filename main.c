#include "push_swap.h"

void printf_flags_values(t_flags_values *flags_values)
{
	if (!flags_values)
		return;
	printf("Simple: %d\n", flags_values->simple);
	printf("Medium: %d\n", flags_values->medium);
	printf("Complex: %d\n", flags_values->complex);
	printf("Adaptive: %d\n", flags_values->adaptive);
	printf("Bench: %d\n", flags_values->bench);
}

int	sum_flags(t_flags_values *flags_values)
{
	if (!flags_values)
		return (0);
	return (flags_values->simple + flags_values->medium + flags_values->complex
		+ flags_values->adaptive + flags_values->bench);
}

int	main(int argc, char **argv)
{
	t_stacks		*data;
	t_flags_values	*flags;

	flags = NULL;
	argv++; // Skip program name
	if ((*argv)[0] == '-' && (*argv)[1] == '-')
		flags = check_flags(argv);
	printf_flags_values(flags);
	argv += sum_flags(flags);

	data = parse_args(argc, argv);
	printf("int = %i\n", data->a->top->value);
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
