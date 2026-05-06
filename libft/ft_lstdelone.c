/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:21:22 by mifranci          #+#    #+#             */
/*   Updated: 2026/03/19 00:35:18 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!(lst))
		return ;
	del(lst->content);
	free(lst);
}

/*#include <stdio.h>
int main()
{
	t_list *node = ft_lstnew(malloc(5));
	ft_lstdelone(node, free);
	return (0);
}*/