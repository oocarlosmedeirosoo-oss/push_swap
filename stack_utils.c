#include "push_swap.h"

// Verifica se a stack está ordenada m > M, retorna 1 se ordenada, 0 se não.
int	is_sorted(t_stack *s)
{
	t_node	*tmp;

	if (!s || s->size < 2)
		return (1);
	tmp = s->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Retorna a posição (0 = topo) do elemento com valor mínimo.
int	find_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	if (!s || s->size == 0)
		return (-1);
	tmp = s->top;
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
int	find_max_pos(t_stack *s)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		i;

	if (!s || s->size == 0)
		return (-1);
	tmp = s->top;
	max = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

// Retorna o índice normalizado do nó na posição pos (0 = topo).
int	get_index_at(t_stack *s, int pos)
{
	t_node	*tmp;
	int		i;

	if (!s || pos < 0 || pos >= s->size)
		return (-1);
	tmp = s->top;
	i = 0;
	while (i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->index);
}

// Atribui índices 0..n-1 a cada nó com base na ordem dos valores.
void	assign_indices(t_stack *s)
{
	t_node	*i;
	t_node	*j;
	int		index;

	if (!s)
		return ;

	i = s->top;
	while (i)
	{
		index = 0;
		j = s->top;
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
