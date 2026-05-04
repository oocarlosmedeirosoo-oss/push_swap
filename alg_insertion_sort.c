#include "push_swap.h"

int wrong_index(t_stack *a)
{
	int	i;

	i = 0;
	while (a->data < a->next->data)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int smallest_value(t_stack *a)
{
	int i;

	i = a->data;
	while (a)
	{
		if (i > a->data)
			i = a->data;
		a = a->next;
	}
	return (i);
}
/* void bubble_sort(t_stack **a, t_stack **b)
{
	int smallest;
	int wrong;
	(void)b;
	int i = 0;

	smallest = smallest_value(*a);
	while (disorder(*a) != 0)
	{
		if ((*a)->data > (*a)->next->data)
		{
			sa(a, b);
			i++;
		}
		while ((*a)->data != smallest)
		{
			ra(a, b);
			i++;
		}
		if ((*a)->data == smallest && disorder(*a) == 0)
			break;
		wrong = wrong_index(*a);
		if (wrong != 0)
			while (wrong--)
			{
				ra(a, b);
				i++;
			}
				
	}
	printf("OPERA;OES = %i\n", i); 
} */

// Custom sort ------
int max_value(t_stack *a)
{
	int i;

	i = a->data;
	while (a)
	{
		if (i < a->data)
			i = a->data;
		a = a->next;
	}
	return (i);
}

int max_index(t_stack *a, int max_value)
{
	int i = 0;
	while (a->data != max_value)
	{
		i++;
		a = a->next;
	}
	return (i);
	
}

void custom_sort(t_stack **a, t_stack **b)
{
	size_t counter = 0;
	size_t size = ft_lstsize(*a);
	size_t i;
	size_t size_b;
	(void)size_b;
	// move all values to t_stack b
	while (*a)
	{
		pb(a, b); counter++;
	}

	// find max value in t_stack b, rotate untill its on top and push a
	while (ft_lstsize(*a) != size)
	{
		size_b = ft_lstsize(*b);
		i = max_index(*b, max_value(*b));

		if (i <= size_b / 2)
		{
			while (i--)
			{
				rb(a, b); counter++;
			}
		}
		else
		{
			while (i++ != size_b)
			{
				rrb(a, b); counter++;
			}
		}
		pa(a, b); counter++;
	}
	/* printf("OPERA;OES = %li\n", counter); */
}

/* void custom_sort(t_stack **a, stack **b)
{
	size_t counter = 0;
	size_t size = ft_lstsize(*a);
	size_t i = size;
	size_t size_b;
	(void)size_b;
	// move all values to stack b
	while (i--)
	{
		pb(a, b); counter++;
	}

	// find max value in stack b, rotate untill its on top and push a
	while (ft_lstsize(*a) != size)
	{
		size_b = ft_lstsize(*b);
		i = max_index(*b, max_value(*b));
		
		while (i--)
		{
			rb(a, b); counter++;
		}	
		pa(a, b); counter++;
	}
	printf("OPERA;OES = %li\n", counter);
} */