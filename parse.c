/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:53:11 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 17:39:22 by mifranci         ###   ########.fr       */
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

static void	parse_args_helper(char **splitted, char **argv, t_stacks *data, t_bench_stats *bench)
{
	int		i;
	t_node	*new;
	int		value;

	while (*argv)
	{
		i = 0;
		splitted = ft_split(*argv++, ' ');
		if (!*splitted)
		{
			free_split(splitted);
			ft_error(data, bench);
		}
		while (splitted[i])
		{
			if (!ft_atoi_safe(splitted[i], &value))
				ft_error(data, bench);
			if (has_duplicate(data->a, value))
				ft_error(data, bench);
			new = node_new(value, data, bench);
			stack_addback(data->a, new);
			i++;
		}
		free_split(splitted);
	}
}

t_stacks	*parse_args(char **argv, t_bench_stats *bench)
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
		return (ft_error(data, bench), NULL);
	parse_args_helper(splitted, argv, data, bench);
	return (data);
}

void	ft_error(t_stacks *data, t_bench_stats *bench)
{
	data_free(data, bench);
	write(2, "Error\n", 6);
	exit(1);
}
