#include "push_swap.h"

// Verifica se a stack está ordenada m > M, retorna 1 se ordenada, 0 se não.
int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Retorna a posição (0 = topo) do elemento com valor mínimo.
int	find_min_pos(t_stack *stack)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	if (!stack || stack->size == 0)
		return (-1);
	tmp = stack->top;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

// Retorna a posição (0 = topo) do elemento com valor máximo.
int	find_max_pos(t_stack *stack)
{
	t_node	*temp;
	int		max;
	int		pos;
	int		i;

	if (!stack || stack->size == 0)
		return (-1);
	temp = stack->top;
	max = temp->value;
	pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

// Retorna o índice normalizado do nó na posição pos (0 = topo).
int	get_index_at(t_stack *stack, int pos)
{
	t_node	*temp;
	int		i;

	if (!stack || pos < 0 || pos >= stack->size)
		return (-1);
	temp = stack->top;
	i = 0;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return (temp->index);
}

// Atribui índices 0..n-1 a cada nó com base na ordem dos valores.
void	assign_indices(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		index;

	if (!stack)
		return ;

	i = stack->top;
	while (i)
	{
		index = 0;
		j = stack->top;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}
