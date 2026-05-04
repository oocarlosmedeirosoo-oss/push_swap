#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_stack *newnode(int data)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void    push_top(t_stack **a, t_stack *new)
{
    if (!new)
        return;
    new->next = *a;
    *a = new;
}

void    print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("data: %d | addr: %p | next: %p\n",
            stack->data, stack, stack->next);
        stack = stack->next;
    }
}

// Swap the first two elements at the top of stack a. - Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	t_stack *temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}
// Swap the first two elements at the top of stack b - Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
	t_stack *temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
}
// Swap sa and sb at the same time.
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
// Take the first element at the top of b and put it at the top of a. - Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}
// Take the first element at the top of a and put it at the top of b. - Do nothing if b is empty.
void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}
//Shift up all elements of stack a by one. - The first element becomes the last one.
void	ra(t_stack **a)
{
	t_stack *first;
	t_stack *current;

	if (!a || !(a) || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
}
//  Shift up all elements of stack b by one. The first element becomes the last one.
void	rb(t_stack **b)
{
	t_stack *first;
	t_stack *current;

	if (!b || !(b) || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	current = *b;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}


/* 
rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
rrr : rra and rrb at the same time. */

int main(void)
{
    t_stack *a = NULL;
	t_stack *b = NULL;
	ft_disorder_metric(a);
	printf("Stack A: Valores Iniciais\n");
    push_top(&a, newnode(3));
    push_top(&a, newnode(1));
    push_top(&a, newnode(2));
	push_top(&a, newnode(5));
	push_top(&a, newnode(4));
	print_stack(a);
	ft_disorder_metric(a);
	printf("\n");
	printf("Stack B: Inicialmente a 0\n");
	print_stack(b);
	printf("\n");
	ft_disorder_metric(a);

	printf("Exec SA - Swap the first two elements at the top of stack a.\n");
	printf("Stack A:\n");
	sa(&a);
	print_stack(a);
	printf("Stack B: \n");
	print_stack(b);
	printf("\n");

	printf("Exec PB - Take the first element at the top of a and put it at the top of b.\n");
	printf("Stack A:\n");
	pb(&a, &b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("Exec PB - Take the first element at the top of a and put it at the top of b.\n");
	printf("Stack A:\n");
	pb(&a, &b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("Exec SB - Swap the first two elements at the top of stack b.\n");
	printf("Stack A:\n");
	sb(&b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("Exec SS - Swap sa and sb at the same time.\n");
	printf("Stack A:\n");
	ss(&a, &b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("Exec PB - Take the first element at the top of a and put it at the top of b.\n");
	printf("Stack A:\n");
	pb(&a, &b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("PA - Take the first element at the top of b and put it at the top of a.\n");
	printf("Stack A:\n");
	pa(&a, &b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n"); 

	printf("RA -  Shift up all elements of stack a by one. The first element becomes the last one\n");
	printf("Stack A:\n");
	ra(&a);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("RB -  Shift up all elements of stack a by one. The first element becomes the last one\n");
	printf("Stack A:\n");
	rb(&b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

	printf("RR -  Shift up all elements of stack ra and rb at the same time.\n");
	printf("Stack A:\n");
	rr(&a, &b);
	print_stack(a);
	printf("Stack B:\n");
	print_stack(b);
	printf("\n");

    return 0;
}
