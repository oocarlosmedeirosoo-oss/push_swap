/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:23:52 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/17 16:45:46 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_intlen(long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*writetostring(char *str, int k, int i, long n)
{
	while (k > 0)
	{
		str[i] = ((n / k) % 10) + '0';
		k /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*handle_neg(long *nbr, int *sign, char *res, int i)
{
	*nbr *= -1;
	*sign *= -1;
	res = malloc(sizeof(char) * (ft_intlen(*nbr) + 2));
	if (!res)
		return (NULL);
	res[i++] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		k;
	int		sign;
	long	nbr;

	nbr = n;
	sign = 1;
	i = 0;
	k = 1;
	res = NULL;
	if (n == 0)
		return (writetostring(malloc(sizeof(char) * (2)), k, i, nbr));
	if (nbr < 0)
		res = handle_neg(&nbr, &sign, res, i++);
	else
		res = malloc(sizeof(char) * (ft_intlen(nbr) + 1));
	if (!res)
		return (NULL);
	while (nbr / k > 9)
		k *= 10;
	return (writetostring(res, k, i, nbr));
}

/*int main()
{
	char *res;
	res = ft_itoa(1223);
	printf("res = %s\n", res);
	free(res);
	res = ft_itoa(2147483647);
	printf("res = %s\n", res);
	free(res);
	res = ft_itoa(-2147483648);
	printf("res = %s\n", res);
	free(res);
	res = ft_itoa(0);
	printf("res = %s\n", res);
	free(res);
	return 0;
}*/