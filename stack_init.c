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
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

// Insere um nó no TOPO da stack. Usado no parsing para construir a stack a.
void	stack_push_top(t_stack *s, t_node *node)
{
	if (!s || !node)
		return ;

	node->next = s->top;
	s->top = node;
	s->size++;
}

// Liberta todos os nós de uma stack e a própria stack.
void	stack_free(t_stack *s)
{
	t_node	*tmp;

	if (!s)
		return ;
	while (s->top)
	{
		tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}
	free(s);
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