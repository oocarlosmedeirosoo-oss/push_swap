/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:50:15 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/23 21:23:11 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	int	count;

	count = write (1, &c, 1);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_print_str(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (str == NULL)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		count += write (1, &str[i], 1);
		i++;
	}
	return (count);
}