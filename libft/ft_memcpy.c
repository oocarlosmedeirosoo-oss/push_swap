/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:42:23 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 16:01:45 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = dest;
	ptr2 = src;
	while (n-- > 0)
		*ptr1++ = *ptr2++;
	return (dest);
}

/*#include <stdio.h>
int main()
{
	char dest[] = "hello";
	ft_memcpy(dest, "aaa", 3);
	printf("res = %s\n", dest); 
	return 0;
}
*/