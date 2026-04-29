/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:27:07 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/18 13:08:52 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	size_t	i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*new;
	long	num;

	num = n;
	i = ft_count_digits(n);
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	new[i--] = '\0';
	if (num == 0)
		new[0] = '0';
	if (num < 0)
	{
		new[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		new[i--] = (num % 10) + '0';
		num = num / 10;
	}
	return (new);
}
