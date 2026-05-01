/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:16:27 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/23 23:00:54 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dispatch(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), type));
	else if (type == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	int		i;

	if (!str)
		return (-1);
	va_start (ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break;
			count += ft_dispatch(str[i], &ap);
		}
		else
			count += write (1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

