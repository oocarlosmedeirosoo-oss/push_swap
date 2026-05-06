/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:27:10 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 19:03:08 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size == 0)
		return (malloc(0));
	if (nmemb > (INT_MAX) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* #include <stdio.h>
int main()
{
	int numItems = 15;
	int *myArray = ft_calloc(2147483640, sizeof(int));
 	printf("res = %p\n", myArray);
	for(int i = 0; i < numItems; i++) {
		myArray[i] = i + 1;
	}

	for(int i = 0; i < numItems; i++) {
		printf("%d ", myArray[i]);
	}
	free(myArray);
	myArray = NULL;

	return 0;
}
 */