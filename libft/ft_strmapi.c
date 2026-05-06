/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:28:29 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/17 16:19:20 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char ft_subchr(unsigned int i, char c) 
{
	return ('c');
}
char ft_showindex(unsigned int i, char c) 
{
	return (i + '0');
}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup(s);
	if (!result)
		return (NULL);
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}

/*int main()
{
	char *res = ft_strmapi("1234", ft_subchr);
	printf("res = %s\n", res);
	free(res);
	res = ft_strmapi("1234", ft_showindex);
	printf("res = %s\n", res);
	free(res);
	return 0;
}
*/