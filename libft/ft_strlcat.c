/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 02:33:21 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/19 01:46:37 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	b_to_append;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dsize <= dst_len)
		return (src_len + dsize);
	b_to_append = dsize - dst_len - 1;
	dst += dst_len;
	while (b_to_append-- > 0 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len + dst_len);
}

/* #include <stdio.h>
int main(int argc, char const *argv[])
{
	char *s = "aaa";
	char dest[10] = "bb";
	printf("result before = %s\n", dest);
	printf("len = %zu\n", ft_strlcat(dest, s, 7));
	printf("result after = >%s<\n", dest);
	return 0;
}*/