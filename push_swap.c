/* void push_a(int *a)
{
	
}

void push_b(int *b)
{

} */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	int	i;
	stack	*a;
	stack	*b;

	i = 1;
/* 	if (check_valid_argv(argc, argv))
	{
		printf("Error: argument that is not an int\n");
		return (1);
	} */
/* 	a = NULL;
	b = NULL;
	while (i < argc)
		add_back(&a, argv[i++]);
	printf("dis metric = %f\n", disorder(a));

	printf_stacks(a, b, "i");

	bubble_sort(&a, &b);
	
	printf_stacks(a, b, "i");
	sa(&a); printf_stacks(a, b, "sa"); */

/* 	i = 3;
	while (i--)
	{
		pb(&a, &b); printf_stacks(a, b, "pb");
	}

	ra(&a); printf_stacks(a, b, "ra");

	rb(&b); printf_stacks(a, b, "rb");
	
	rra(&a); printf_stacks(a, b, "rra");

	rrb(&b); printf_stacks(a, b, "rrb");

	sa(&a); printf_stacks(a, b, "sa");
	
	i = 3;
	while (i--)
	{
		pa(&a, &b); printf_stacks(a, b, "pa");
	}
	 */

	
	
	return 0;
}

/* 
	ra(&a); write(1, "ra\n", 3);

	pb(&a, &b); write(1, "pb\n", 3);

	rra(&a); write(1, "rra\n", 4);

	i = 2;
	while (i--)
	{
		pb(&a, &b); write(1, "pb\n", 3);
	}

	ra(&a); write(1, "ra\n", 3);

	pb(&a, &b); write(1, "pb\n", 3);


	ra(&a); write(1, "ra\n", 3);
	pb(&a, &b); write(1, "pb\n", 3);
	pb(&a, &b); write(1, "pb\n", 3);
	
	i = 6;
	while (i--)
	{
		pa(&a, &b); write(1, "pa\n", 3);
	} */