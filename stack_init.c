#include "push_swap.h"

// Cria um novo nó com o valor dado. Preencher depois o index com assign_indices().
t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

// Cria uma stack vazia.
t_stack	*stack_new(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

// Insere um nó no TOPO da stack. Usado no parsing para construir a stack a.
void	stack_push_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;

	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

// Liberta todos os nós de uma stack e a própria stack.
void	stack_free(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

// Liberta tudo o que está no t_data.
void	data_free(t_stacks *data)
{
	if (!data)
		return ;
	if (data->a)
		stack_free(data->a);
	if (data->b)
		stack_free(data->b);
	free(data);
}