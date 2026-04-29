/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:18:34 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/16 17:37:49 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	if (size == 0)
		return (i);
	j = 0;
	while (src[j] && j < (size - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
