#include "push_swap.h"

// O fundo da stack passa a ser o topo. Utilizacao de static para o codigo ficar mais limpo.
static void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
//Eles dizem Operations must be separated by a \n and nothing else.

//  Shift down all elements of stack a by one.
void	rra(t_stacks *data)
{
	reverse_rotate(data->a);
	write(1, "rra\n", 4);
}
//  Shift down all elements of stack b by one.
void	rrb(t_stacks *data)
{
	reverse_rotate(data->b);
	write(1, "rrb\n", 4);
}

// Shift rra and rrb at the same time.
void	rrr(t_stacks *data)
{
	reverse_rotate(data->a);
	reverse_rotate(data->b);
	write(1, "rrr\n", 4);
}
