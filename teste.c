#include <stdlib.h>
#include <stdio.h>

#include "push_swap.h"


stack *lstnew(int data)
{
	stack *new;

	new = malloc(sizeof(stack));
	if(!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}


void lstfront(stack **a, stack *new)
{
	new->next = *a;
	*a = new;
}

void tua_ft(stack **a)
{
	int i;

	i = 1;
	while (i <= 5)
	{
		lstfront(a, lstnew(i));
		i++;
	}
}


void print_s(stack *x)
{
	while (x)
	{
		printf("%li\n", x->data);
		x = x->next;
	}
}

void sa(stack **a, stack **b)
{
	stack *temp;

	if ((*a) && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
	printf_stacks(*a, *b, "sa");
}


void pb(stack **a, stack **b)
{
	stack *temp;

	if ((*a))
	{
		temp = *b;
		*b = *a;
		*a = (*a)->next;
		if (!(*b))
			(*b)->next = NULL;
		else
			(*b)->next = temp;
	}
	printf_stacks(*a, *b, "pb");
}


int main(void)
{
	stack *a = NULL;
	tua_ft(&a);
 	stack *b = NULL;
	printf_stacks(a, b, "i");
/* 	printf("\n");
	pb(&a, &b);
	printf("a\n"); print_s(a);
	printf("\nb\n"); print_s(b);
	printf("\n"); */

	/* printf("\n");
	pb(&a, &b);
	printf("Stack A: \n"); print_s(a);
	printf("\n");
	printf("Stack B: \nb\n"); print_s(b);

	printf("\n");
	pb(&a, &b);
	printf("Stack A: \n"); print_s(a);
	printf("\n");
	printf("Stack B: \nb\n"); print_s(b); */

	sa(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);


	return 0;
}
