/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:36:02 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/14 20:04:46 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *ptr)
{
	int		sign;
	int		res;

	sign = -1;
	res = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
		if (*ptr++ == '-')
			sign = 1;
	while (*ptr >= '0' && *ptr <= '9')
		res = (res * 10) - (*ptr++ - '0');
	return (res * sign);
}

/* #include <stdio.h>
int main()
{
	printf("%i\n", ft_atoi(NULL));
} */