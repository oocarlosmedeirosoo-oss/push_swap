/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:53:01 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/06 18:41:45 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_u(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_printf_u(nbr / 10);
	ft_putchar_fd((nbr % 10) + '0', 1);
	return (count + 1);
}
