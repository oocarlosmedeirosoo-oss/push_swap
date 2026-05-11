/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:52:03 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:28:52 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_atoi_safe(char *str, int *value)
{
	long	result;
	int		sign;

	if (!str || !*str)
		return (0);
	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!(*str))
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (0);
		str++;
	}
	*value = (int)(result * sign);
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	choose_what_to_do(t_stacks *data, t_flags *flags, t_bench_stats *bench)
{
	int	print;

	if (!flags)
	{
		sort_adaptive(data, 1, bench);
		return ;
	}
	print = 1;
	if (flags->bench == 1)
		print = 0;
	if (sum_flags(flags))
	{
		if (flags->simple)
			sort_simple(data, print, bench);
		else if (flags->medium)
			sort_medium(data, print, bench);
		else if (flags->complex)
		{
			sort_complex(data, print, bench);
			bench->strategy = "Complex / O(n log n)";
		}
		else
			sort_adaptive(data, print, bench);
	}
}
