/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:55:40 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/19 01:39:59 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dsize == 0)
		return (src_len);
	while (--dsize > 0 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}

/*#include <stdio.h>
int main(int argc, char const *argv[])
{
	char *s = "hhsss";
	char dest[10] = "AAAAAAAAAA";
	int i = 0;
	printf("result before = %s\n", dest);
	printf("len = %zu\n", ft_strlcpy(dest, s, -4));
	printf("result after = >%s<\n", dest);
	return 0;
}*/