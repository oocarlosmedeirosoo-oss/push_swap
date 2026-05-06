/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:27:46 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/13 11:28:17 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	count;
	size_t	nbr;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	count = 0;
	nbr = n;
	while (*haystack && nbr-- > 0)
	{
		if ((ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			&& ((count + ft_strlen(needle)) <= n))
			return ((char *)haystack);
		count++;
		haystack++;
	}
	return (NULL);
}

/*#include <stdio.h>
int main()
{
	printf("res = %s\n", ft_strnstr("hello", "ll", 4));
	printf("res = %s\n", ft_strnstr("hello", "ll", 3));
	printf("res = %s\n", ft_strnstr("hello", "lo", 5));
	printf("res = %s\n", ft_strnstr("hello", "o", 5));
	printf("res = %s\n", ft_strnstr("hello", "o", 0));
	printf("res = %s\n", ft_strnstr("hello", "o", -2));
	printf("res = %s\n", ft_strnstr("hello", "", 0));
	printf("res = %s\n", ft_strnstr("", "c", 1));
	return 0;
}
*/