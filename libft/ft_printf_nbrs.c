/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:01:58 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/23 21:17:43 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	int		count;
	long	nbr;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += write (1, "-", 1);
		nbr = -nbr;
	}
	count += ft_print_unsigned((unsigned int)nbr);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += write (1, &"0123456789"[n % 10], 1);
	return (count);
}