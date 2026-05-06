/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:42:42 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/11 16:04:02 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*#include <stdio.h>
void addone(void *ptr)
{
	char *ptr1 = (char *)ptr;

	while (*ptr1)
	{
		*ptr1 += 1;
		printf("%c", *ptr1);
		ptr1++;
	}
	printf("%c\n", *ptr1);
}
int main(int argc, char const *argv[])
{
	char str[] = "gdkkn";
	char str1[] = "rldfnk";
	t_list *head = ft_lstnew(str);
	ft_lstadd_back(&head, ft_lstnew(str1));
	ft_lstiter(head, addone);
	head = NULL;
	ft_lstiter(head, addone);
	return 0;
}*/