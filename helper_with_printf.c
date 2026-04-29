/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_with_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:58 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/29 20:29:48 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printf_stacks(stack *a, stack *b, char *str)
{
	printf("---------------------------------------------\n");
	decifer(str);
	while (a || b)
	{
		if (a)
			printf("%li ", a->data);
		else
			printf("  ");
		if (b)
			printf("%li", b->data);
		printf("\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("_ _\na b\n");
}

void decifer(char *s)
{
	if (*s == 'i')
		printf("Init a and b:\n");
	else if (*s == 's' && s[1] == 'a')
		printf("Exec sa:\n");
	else if (*s == 's' && s[1] == 'b')
		printf("Exec sb:\n");
	else if (*s == 's' && s[1] == 's')
		printf("Exec ss:\n");
	else if (*s == 'p' && s[1] == 'a')
		printf("Exec pa:\n");
	else if (*s == 'p' && s[1] == 'b')
		printf("Exec pb:\n");
	else if (*s == 'r' && s[1] == 'a')
		printf("Exec ra:\n");
	else if (*s == 'r' && s[1] == 'b')
		printf("Exec rb:\n");
	else if (*s == 'r' && s[1] == 'r' && s[2] == '\0')
		printf("Exec rr:\n");
	else if (*s == 'r' && s[1] == 'r' && s[2] == 'a')
		printf("Exec rra:\n");
	else if (*s == 'r' && s[1] == 'r' && s[2] == 'b')
		printf("Exec rrb:\n");
	else if (*s == 'r' && s[1] == 'r' && s[2] == 'r')
		printf("Exec rrr:\n");
}