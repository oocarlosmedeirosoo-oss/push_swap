/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:20:58 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/17 16:17:16 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr1;
	char	*result;

	ptr1 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr1)
		return (NULL);
	result = ptr1;
	ptr1 = ft_memcpy(ptr1, s1, ft_strlen(s1));
	ptr1 = ft_memcpy(ptr1 + ft_strlen(s1), s2, ft_strlen(s2));
	ptr1 = ft_memcpy(ptr1 + ft_strlen(s2), "\0", 1);
	return (result);
}

/* #include <stdio.h>
int main()
{
	char *s1 = NULL;
	char *s2 = "a\0a";
	char *res = ft_strjoin(s1, s2);
	printf("res = >%s<\n", res);
	return 0;
} */