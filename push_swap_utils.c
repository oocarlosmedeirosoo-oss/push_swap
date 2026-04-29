/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:33:39 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/29 20:28:05 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(stack *a)
{
	float	total_pairs;
	float mistakes;
	stack	*next;

	next = a->next;
	mistakes = 0;
	total_pairs = 0;
	while (next)
	{
		total_pairs++;
		if (a->data > next->data)
			mistakes++;
		a = a->next;
		next = next->next;
	}
 	printf("total_pairs = %0.2f\n", total_pairs);
	printf("mistakes = %0.2f\n", mistakes);
	if (!mistakes)
		return (0);
	return (mistakes / total_pairs);
}


int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		sign;
	int		res;

	ptr = (char *)nptr;
	sign = 1;
	res = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = (res * 10) + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}

void add_back(stack **head, const char *data)
{
	stack	*node;
	stack	*i;

	node = malloc(sizeof(*node));
	node->data = ft_atoi(data);
	node->next = NULL;
	if (*head)
	{
		i = *head;
		while (i->next)
			i = i->next;
		i->next = node;
	}
	else
		*head = node;
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int check_valid_argv(int argc, char const **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
			j++;
		while (argv[i][j])
			if (!(ft_isdigit(argv[i][j++])))
				return (1);
		i++;
	}
	return (0);
}

void add_top(stack **head, int data)
{
	stack *node;
	
	node = malloc(sizeof(*node)); 
	node->data = data;
	node->next = NULL;
	if (*head)
	{
		node->next = *head;
		*head = node;
	}
	else
		*head = node;
}

/* float	disorders(stack a)
{
	int	mistakes;
	int	total_pairs;
	
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs
}

int	stack_size(stack a)
{
	
} */




/* 
int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		sign;
	int		res;

	ptr = (char *)nptr;
	sign = 1;
	res = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = (res * 10) + (*ptr - '0');
		ptr++;
	}
	printf("res = %i\n", res);
	return (res * sign);
}

s_node	*add_top(s_node *head, const char *nb)
{
	s_node	*new_head;

	new_head = malloc(sizeof(*new_head));
	new_head->nb = ft_atoi(nb);
	new_head->next = NULL;
	if (!head)
		return (new_head);
	new_head->next = head;
	return (new_head);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int check_valid_argv(int argc, char const **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		if (!(ft_isdigit(ft_atoi(argv[i]))))
			return (1);
	return (0);
} */