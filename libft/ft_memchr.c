/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:38:05 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/19 01:40:22 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*int main()
{
	char s64[] = {0, 1, 2 ,3 ,4 ,5};
	char *lok = ft_memchr(s64, 3, 4);
	printf("ft_memchr = >%p<\n", lok);
	printf("ft_memchr = >%i<\n", lok[0]);
	return 0;
}
*/