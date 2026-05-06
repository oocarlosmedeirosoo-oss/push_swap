#include "push_swap.h"

/* Remove o nó do topo da stack src. Utilizacao de static para o codigo ficar mais limpo*/
static void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	if (!src || src->size == 0)
		return ;
	temp = src->top;
	src->top = temp->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}

//Eles dizem Operations must be separated by a \n and nothing else.

// pa: tira o topo de b e coloca no topo de a.
void	pa(t_stacks *data, int print)
{
	push(data->b, data->a);
	if (print)
		write (1, "pa\n", 3);
}

// pb: tira o topo de a e coloca no topo de b.
void	pb(t_stacks *data, int print)
{
	push(data->a, data->b);
	if (print)
		write (1, "pb\n", 3);
}
