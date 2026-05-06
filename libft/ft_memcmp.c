/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:05:20 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/17 16:08:01 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}

/*#include <stdio.h>
int main()
{
	int x[] = {1, 2, 3};
	int y[] = {1, 3, 4};
	printf("res = %i\n", ft_memcmp(&x, &y, 5));
 	printf("res = %i\n", ft_memcmp("hello", "hello", 5));
	printf("res = %i\n", ft_memcmp("hello", "hello", 0));
	printf("res = %i\n", ft_memcmp("hello", "iello", 1));
	printf("res = %i\n", ft_memcmp("iello", "hello", 1));
	printf("res = %i\n", ft_memcmp("iello", "hello", 5));
	printf("res = %i\n", ft_memcmp("hella", "hellb", 5));
	printf("res = %i\n", ft_memcmp("hellb", "hella", 5));
	printf("res = %i\n", ft_memcmp("hellb", "hell", 5));
	printf("res = %i\n", ft_memcmp("hell", "hellb", 5)); 
	return 0;
}*/