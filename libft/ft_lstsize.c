/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 07:55:40 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/09 08:17:52 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list *test_null = NULL;
	printf("nbr nodes = %i\n", ft_lstsize(test_null));
	t_list node;
	t_list node1;
	t_list node2;
	node.content = "hello";
	node.next = &node1;
	
	node1.content = "smegol";
	node1.next = &node2;

	node2.content = "ffff";
	node2.next = NULL;
	printf("nbr nodes = %i\n", ft_lstsize(&node));
	node.next = NULL;
	printf("nbr nodes = %i\n", ft_lstsize(&node));
	return (0);
}*/