#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (check_valid_argv(argc, argv, &a))
	{
		printf("Error: argument that is not an int\n");
		return (1);
	}
	/* printf_stacks(a, b, "i"); */
	if (int_repeated(a) == 1)
	{
		printf("Error: int_repeated\n");
		return (1);
	}
/* 	printf("dis metric = %f\n\n", ft_disorder_metric(a)); */
	/* printf_stacks(a, b, "i"); */

	/* bubble_sort(&a, &b); */
	custom_sort(&a, &b);
	
	/* printf_stacks(a, b, "i"); */

	/* printf_stacks(a, b, "i"); */

	
	return 0;
	
	
	
}