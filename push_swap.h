/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:46:03 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/04 13:32:42 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int             data;
    struct s_stack  *next;
}   t_stack;

void custom_sort(t_stack **a, t_stack **b);


// ope_swap_push.c - 5 funcions
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// ope_rotate.c - 5 funcions
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **a, t_stack **b);

// lst_utils.c - 2 funcions
void add_back(t_stack **head, const char *data);
size_t     ft_lstsize(t_stack *lst);

//utils.c - 5 funcions (includding static)
void    ft_bzero(void *s, size_t n);
char    **ft_split(char const *s, char c);

// veri_utils.c - 5 funcions
int     ft_isdigit(int c);
char    *ft_strchr(const char *s, int c);
int     ft_atoi(const char *nptr);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);

// verifications.c
void    rrr(t_stack **a, t_stack **b);
float   ft_disorder_metric(t_stack *a);
int     check_valid_argv(int argc, char const **argv, t_stack **a);
int     int_repeated(t_stack *a);



#endif