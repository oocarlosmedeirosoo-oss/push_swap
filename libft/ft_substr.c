/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:34:54 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 19:46:09 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*tmp;
	size_t	substr_len;

	if (!s || start > ft_strlen(s))
	{
		substr = malloc(sizeof(*substr));
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	s += start;
	substr_len = ft_strlen(s);
	if (substr_len > len)
		substr_len = len;
	substr = malloc(sizeof(*substr) * (substr_len + 1));
	if (!substr)
		return (NULL);
	tmp = substr;
	while (*s && substr_len--)
		*substr++ = *s++;
	*substr = '\0';
	return (tmp);
}

/*#include <stdio.h>
int main()
{
	char *res = ft_substr("aa", 2, 22);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("tripouille", 0, 5);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("tripouille", 1, -1);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("BONJOUR LES HAR ICOTS !", 8, 3);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("test", 1, 99999999);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("", 99999999, 0);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("sss", 99999999, 2);
	printf("res = >%s<\n", res);
	free(res);
	res = ft_substr("", 0, 0);
	printf("res = >%s<\n", res);
	free(res);
	return 0;
}*/