/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:10:23 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/18 13:57:11 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dest || !src)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (ptr1 > ptr2)
	{
		while (n > 0)
		{
			n--;
			ptr1[n] = ptr2[n];
		}
	}
	else
		ft_memcpy(ptr1, ptr2, n);
	return (dest);
}
