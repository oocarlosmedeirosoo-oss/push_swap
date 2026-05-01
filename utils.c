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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	j = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			j = -1;
		i++;
	}
	k = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = (k * 10) + (nptr[i] - '0');
		i++;
	}
	return (k * j);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int verifications(char *str)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		if (argv[i][j] )
	}
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
