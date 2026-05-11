/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:16:57 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:59:55 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value, t_stacks *data, t_ptr_b_f ptrs_b_f)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		ft_error(data, ptrs_b_f, NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

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

void	stack_addback(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
		stack->size++;
		return ;
	}
	temp = stack->top;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	stack->size++;
}

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

void	data_free(t_stacks *data, t_bench_stats *bench, t_flags *flags)
{
	if (flags)
		free(flags);
	free(bench);
	if (!data)
		return ;
	if (data->a)
		stack_free(data->a);
	if (data->b)
		stack_free(data->b);
	free(data);
}
