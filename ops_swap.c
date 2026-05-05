#include "push_swap.h"

// Troca os valores dos 2 nós do topo. Utilizacao de static para o codigo ficar mais limpo.
static void	swap_top(t_stack *stack)
{
	t_node * first;
	t_node *second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}
//Eles dizem Operations must be separated by a \n and nothing else.

// Swap the first two elements at the top of stack a.
void	sa(t_stacks *data)
{
	swap_top(data->a);
	write(1, "sa\n", 3);
}
// Swap the first two elements at the top of stack b.
void	sb(t_stacks *data)
{
	swap_top(data->a);
	write(1, "sb\n", 3);
}

// Swap sa and sb at the same time.
void	ss(t_stacks *data)
{
	swap_top(data->a);
	swap_top(data->b);
	write(1, "ss\n", 3);	
}