/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:42:59 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/18 16:36:33 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
int main()
{
	char ar[5] = {1, 1};
	int i = 0;
	while (ar[i])
		printf("res = %i\n", ar[i++]);
	ft_bzero((void *)ar, 2);
	i = 0;
	while (ar[i])
		printf("res = %i\n", ar[i++]);
	return 0;
}*/