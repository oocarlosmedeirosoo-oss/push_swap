/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:10:28 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:52:51 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	init_flags_values(t_flags *flags_values)
{
	flags_values->simple = 0;
	flags_values->medium = 0;
	flags_values->complex = 0;
	flags_values->adaptive = 0;
	flags_values->bench = 0;
}

void	handle_flag(t_flags *flags_values, char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0)
		flags_values->simple += 1;
	else if (ft_strcmp(argv, "--medium") == 0)
		flags_values->medium += 1;
	else if (ft_strcmp(argv, "--complex") == 0)
		flags_values->complex += 1;
	else if (ft_strcmp(argv, "--adaptive") == 0)
		flags_values->adaptive += 1;
	else if (ft_strcmp(argv, "--bench") == 0)
		flags_values->bench += 1;
	else
	{
		ft_printf("Error\n");
		free(flags_values);
		exit(1);
	}
}

t_flags	*check_flags(char **argv)
{
	t_flags	*flags_values;

	flags_values = malloc(sizeof(t_flags));
	if (!flags_values)
		return (NULL);
	init_flags_values(flags_values);
	while (*argv && ((*argv)[0] == '-' && (*argv)[1] == '-'))
		handle_flag(flags_values, *argv++);
	return (flags_values);
}

void	free_memmory_if_not_data(t_flags *flags, t_bench_stats *bench)
{
	free(flags);
	free(bench);
}
