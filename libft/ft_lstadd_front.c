/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 07:07:58 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/13 12:45:41 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
void	ft_lstadd_front(t_list **lst, t_list *node)
{
	node->next = lst[0];
	lst[0] = node;
}

/*int main()
{
	t_list first;
	first.content = "hello";
	first.next = NULL;
	
	t_list *lst = &first;

	t_list node;
	node.content = "smegol";
	node.next = NULL;
	printf("content head   = %s\n", (char *)lst->content);
	printf("address  first = %p\n", &first);
	printf("node next      = %p\n", node.next);
	ft_lstadd_front(&lst, &node);
	printf("content head   = %s\n", (char *)lst->content);
	printf("address  first = %p\n", &first);
	printf("node next      = %p\n", node.next);
	return (0);
}*/