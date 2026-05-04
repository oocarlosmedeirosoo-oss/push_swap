/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_chunk_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:49 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/29 16:13:51 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
float	ft_disorder_metric(t_stack *a)
{
	float	mistakes;
	float	pairs;
	size_t	len_stack;
	t_stack *i;
	t_stack *j;

	mistakes = 0;
	pairs = 0;
	len_stack = ft_lstsize(a);
	if (len_stack < 2)
		return (0.0);
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0);
	printf("total_pairs = %0.2f\n", pairs);
	printf("mistakes = %0.2f\n", mistakes);
	return (mistakes / pairs);
	
}

int check_valid_argv(int argc, char const **argv, t_stack **a)
{
	int	i;
	int	j;
	char *set = "0123456789 -+";
	char **splitted;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && (!ft_isdigit(argv[i][j + 1])))
				return (1);
			if (!(ft_strchr(set, argv[i][j++])))
				return (1);
		}
		splitted - ft_plit(argv[i], ' ');
		while (*splitted)
		{
			ft_lstadd_back(a, *splitted);
			splitted++;
		}
		i++;
	}
	return (0);
}

int	int_repeated(t_stack *a)
{
	t_stack *tmp;
	int max_value;
	int min_value;
	int *array_positive;
	int *array_negative;

	tmp = a;
	max_value = tmp->content;
	min_value = tmp->content;
	while (tmp)
	{
		if (tmp->content > max_value)
			max_value = tmp->content;
		if (tmp->content < min_value)
			min_value = tmp->content;
		tmp = tmp->next;
	}
	array_positive = ft_calloc(sizeof(int), max_value + 1);
	array_negative = ft_calloc(sizeof(int), (min_value + 1) * -1);
	while (a)
	{
		if (a->content < 0)
		{
			array_negative[(a->content) * -1] += 1;
			if (array_negative[(a->content) * -1] > 1)
				return (1);
		}
		else
		{
			array_positive[a->content] += 1;
			if (array_positive[a->content] > 1)
				return (1);
		}
		a = a->next;
	}
	return (0);
}