/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:51:15 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 20:00:58 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/* #include <stdio.h>
int main()
{
	char s[] = "abcdefghj";
	printf("ft_strchr = >%s<\n", ft_strchr(NULL, 'a'));
	printf("ft_strchr = >%s<\n", ft_strchr(s, 'f'));
	printf("ft_strchr = >%s<\n", ft_strchr(s, 'j'));
	printf("ft_strchr = >%s<\n", ft_strchr(s, 'z'));
	printf("ft_strchr = >%s<\n", ft_strchr(s, '\0'));
	return (0);
} */