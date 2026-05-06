/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:55:14 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/06 18:41:29 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long nb, char c)
{
	if (nb >= 16)
		ft_puthex(nb / 16, c);
	if (nb % 16 > 9 && c == 'X')
		ft_putchar_fd(((nb % 16) - 10) + 'A', 1);
	else if (nb % 16 > 9)
		ft_putchar_fd(((nb % 16) - 10) + 'a', 1);
	else
		ft_putnbr_fd(nb % 16, 1);
}

int	ft_hexlen(unsigned long nb, char c)
{
	int	len;

	len = 0;
	while (nb > 0 && ++len)
		nb /= 16;
	if (c == 'p')
		len += 2;
	if (len == 0 && c != 'p')
		len++;
	return (len);
}

int	ft_printf_hex(unsigned long nb, char c)
{
	ft_puthex(nb, c);
	return (ft_hexlen(nb, c));
}

int	ft_printf_ptr(void *ptr)
{
	unsigned long	ptr_c;

	if (!ptr)
		return (ft_printf_str("(nil)"));
	ptr_c = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	ft_puthex(ptr_c, 'p');
	return (ft_hexlen(ptr_c, 'p'));
}
