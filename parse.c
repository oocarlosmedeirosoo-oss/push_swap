/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:53:11 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 16:20:40 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_args_helper(char **splitted, char **argv, t_stacks *data)
{
	int		i;
	t_node	*new;
	int		value;

	while (*argv)
	{
		i = 0;
		splitted = ft_split(*argv++, ' ');
		if (!*splitted)
			ft_error(data);
		while (splitted[i])
		{
			if (!ft_atoi_safe(splitted[i], &value))
				ft_error(data);
			if (has_duplicate(data->a, value))
				ft_error(data);
			new = node_new(value);
			if (!new)
				ft_error(data);
			stack_addback(data->a, new);
			i++;
		}
	}
}

t_stacks	*parse_args(char **argv)
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
		return (ft_error(data), NULL);
	parse_args_helper(splitted, argv, data);
	return (data);
}

void	ft_error(t_stacks *data)
{
	data_free(data);
	write(2, "Error\n", 6);
	exit(1);
}
