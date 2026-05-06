/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:29:30 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 19:05:09 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

/*#include <stdio.h>
int main()
{
	
	t_list *lst = NULL;
	
	ft_lstadd_back(&lst, ft_lstnew("hello"));
	printf("content = %s\n", (char *)lst->content);
	ft_lstadd_back(&lst, ft_lstnew("smeagol"));
	t_list *ptr;
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	printf("content = %s\n", (char *)ptr->content);
	
}*/
/*void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
		
	tmp = *lst;
	if (tmp == NULL)
		tmp = new;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}*/
/*int main()
{
	t_list **lst = NULL;
	t_list *head = ft_lstnew("hello");
	ft_lstadd_back(lst, head);
	printf("content = %s\n", (char *)(*lst)->content);
	lst = &head;
	
	printf("content = %p\n", (*lst)->next);
	ft_lstadd_front(lst, ft_lstnew("node1"));
	printf("content = %p\n", (*lst)->next);
	
	ft_lstadd_front(lst, ft_lstnew("node2"));
	printf("content = %p\n", (*lst)->next);
	
	ft_lstadd_front(lst, ft_lstnew("node3"));
	printf("content = %p\n", (*lst)->next);
	
	t_list *node4 = ft_lstnew("node4");
	ft_lstadd_back(lst, node4);
	t_list	*tmp;
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	printf("ft content = %s\n", (char *)tmp->content);
	printf("ft content = %p\n", tmp->next);
	return 0;
}*/