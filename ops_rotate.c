#include "push_swap.h"

// O topo da stack passa a ser o fundo. Utilizacao de static para o codigo ficar mais limpo.
static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}
//Eles dizem Operations must be separated by a \n and nothing else.

// Shift up all elements of stack a by one
void	ra(t_stacks *data, int print)
{
	rotate(data->a);
	if (print)
		write(1, "ra\n", 3);
}
// Shift up all elements of stack b by one
void	rb(t_stacks *data, int print)
{
	rotate(data->b);
	if (print)
		write(1, "rb\n", 3);
}

// Shift ra and rb at the same time.
void	rr(t_stacks *data, int print)
{
	rotate(data->a);
	rotate(data->b);
	if (print)
		write(1, "rr\n", 3);
}
