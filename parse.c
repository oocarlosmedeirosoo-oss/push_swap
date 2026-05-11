/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:53:11 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:10 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static void	parse_args_helper(char **splitted, char **argv,
			t_stacks *data, t_ptr_b_f ptrs_b_f)
{
	int		i;
	t_node	*new;
	int		value;

	while (*argv)
	{
		i = 0;
		splitted = ft_split(*argv++, ' ');
		if (!*splitted)
			ft_error(data, ptrs_b_f, splitted);
		while (splitted[i])
		{
			if (!ft_atoi_safe(splitted[i], &value))
				ft_error(data, ptrs_b_f, splitted);
			if (has_duplicate(data->a, value))
				ft_error(data, ptrs_b_f, splitted);
			new = node_new(value, data, ptrs_b_f);
			stack_addback(data->a, new);
			i++;
		}
		free_split(splitted);
	}
}

t_stacks	*parse_args(char **argv, t_ptr_b_f ptrs_b_f)
{
	char		**splitted;
	t_stacks	*data;

	splitted = NULL;
	data = malloc(sizeof(t_stacks));
	if (!data)
		return (NULL);
	data->a = stack_new();
	data->b = stack_new();
	if (!data->a || !data->b)
		return (ft_error(data, ptrs_b_f, splitted), NULL);
	parse_args_helper(splitted, argv, data, ptrs_b_f);
	return (data);
}

void	ft_error(t_stacks *data, t_ptr_b_f ptrs_b_f, char **splitted)
{
	if (splitted)
		free_split(splitted);
	data_free(data, ptrs_b_f.bench, ptrs_b_f.flags);
	write(2, "Error\n", 6);
	exit(1);
}

int	sum_flags(t_flags *flags)
{
	if (!flags)
		return (0);
	if ((flags->simple + flags->medium + flags->complex + flags->adaptive) > 1
		|| flags->bench > 1)
	{
		free(flags);
		exit(1);
	}
	return (flags->simple + flags->medium + flags->complex
		+ flags->adaptive + flags->bench);
}
