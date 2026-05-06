/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:18:31 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/19 01:41:17 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>
int main(int argc, char const *argv[])
{
	t_list *head = ft_lstnew("0");
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	t_list *node4 = ft_lstlast(head);
	printf("content = %s\n", (char *)node4->content);
	printf("content = %p\n", node3);
	printf("content = %p\n", node4);
	head = NULL;
	node4 = ft_lstlast(head);
	printf("content = %p\n", node4);
	return 0;
}*/