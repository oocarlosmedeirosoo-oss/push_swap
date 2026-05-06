/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:50:28 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/17 16:23:56 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */
char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;

	if (!s1)
		return (NULL);
	end = s1 + (ft_strlen(s1) - 1);
	while (ft_strchr(set, *s1) && s1 < end)
		s1++;
	start = s1;
	while (ft_strchr(set, *end) && end >= start)
		end--;
	return (ft_substr(start, 0, ++end - start));
}
/* printf("end = %s\n", --end); */
/* printf("start = >%s<\n", s1); */
/* 	printf("end = %s\n", end);
	printf("trimmed_len = %zu\n", ++end - start);
	printf("start = %s\n", start );*/
/* #include <stdio.h>
int main()
{
	char *s1 = "            ";
	char *set = " ";
	char *res = ft_strtrim(s1, set);
	printf("res = >%s<\n", res);
	return 0;
} */
/* char	*ft_strtrim(char const *s1, char const *set)
{
	int		ocurrences;
	char	*ptr1;
	char	*res;

	ocurrences = 0;
	ptr1 = (char *)s1;
	while (*ptr1)
		if (ft_strchr(set, *ptr1++))
			ocurrences++;
	res = malloc(sizeof(char) * ((ft_strlen(s1) - ocurrences) + 1));
	ptr1 = res;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
		{
			ptr1 = ft_memcpy(ptr1, s1, 1);
			ptr1++;
		}
		s1++;
	}
	*ptr1 = '\0';
	return (res);
} */