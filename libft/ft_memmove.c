/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:48:51 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/19 01:39:40 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = dest;
	ptr2 = src;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		*(ptr1 + n) = *(ptr2 + n);
	return (dest);
}

/*#include <stdio.h>
int main()
{
	char dest[] = "1234567";
	void *after = ft_memmove(dest + 2, dest, 3);
	char *res = after;
	printf("should be 12367, res = %s\n", res); 
	return 0;
}*/