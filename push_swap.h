/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:46:03 by mifranci          #+#    #+#             */
/*   Updated: 2026/04/29 20:36:31 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct stack
{
	signed long int	data;
	struct stack *next;
} stack;

/* //nodes - valores e ponteiros para o proximo
typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

//stack - ponteiro para controlar o conteudo da stack em causa
typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;
 */
// ope_push_swap.c
void	sa(stack **a, stack **b);
void	sb(stack **b);
void	ss(stack **a, stack **b);
void printf_stacks(stack *a, stack *b, char *str);
void decifer(char *s);

#endif