/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:02:02 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/06 18:41:38 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_dec_int(int nbr)
{
	int		counter;
	char	*itoa;

	counter = 0;
	ft_putnbr_fd(nbr, 1);
	itoa = ft_itoa(nbr);
	counter = ft_strlen(itoa);
	free(itoa);
	return (counter);
}
