/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:28:56 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/23 15:33:33 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *str, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(sizeof(char) * (n + 1));
	if (!(ptr))
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(*res) * (words + 1));
	j = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		if (*s)
		{
			while (s[i] != c && s[i])
				i++;
			res[j++] = ft_strndup(s, i);
		}
		s += i;
	}
	res[words] = NULL;
	return (res);
}

/* #include <stdio.h>
int main(int argc, char const *argv[])
{
	char **res;


	res = ft_split("ssss sss", ' ');

	int i = 0;
	
	if (res)
	{
		while (res[i])
		{
			printf(">%s<\n", res[i]);
			i++;
		}
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
	
	return 0;
	
} */