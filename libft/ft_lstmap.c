/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:39:48 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 19:18:04 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	new_lst = NULL;
	while (tmp != NULL)
	{
		ft_lstadd_back(&new_lst, (ft_lstnew(f(tmp->content))));
		tmp = tmp->next;
	}
	if (ft_lstsize(lst) != ft_lstsize(new_lst))
		ft_lstclear(&new_lst, del);
	return (new_lst);
}

/*#include <stdio.h>
void *subone(void *content)
{
	char *ptr = (char *)content;
	int i = 0;
	while (ptr[i])
	{
		ptr[i] -= 1;
		i++;
	}
	return ((void *)ptr);
}
int main()
{
	char ar[] = "ifmmp";
	char ar1[] = "tnfbhpm";
	char ar2[] = "hpmmvn";
	
	t_list *head = ft_lstnew(ar);
	
	ft_lstadd_back(&head, ft_lstnew(ar1));
	ft_lstadd_back(&head, ft_lstnew(ar2));
	
	t_list *new_lst = ft_lstmap(head, subone, free);
	t_list *tmp;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	tmp = new_lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content); 
		tmp = tmp->next;
	}
	
	while (new_lst)
	{
		tmp = new_lst->next;
		free(new_lst);
		new_lst = tmp;
	}
	
	return 0;
}*/