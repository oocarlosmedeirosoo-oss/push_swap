/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:08:41 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/18 13:47:33 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;

	ptr1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] == (unsigned char)c)
			return ((void *)(ptr1 + i));
		i++;
	}
	return (NULL);
}
