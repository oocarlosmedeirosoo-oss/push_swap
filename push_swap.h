#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

// Nodes para indexacao
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
} t_node;

// Stack com ponteiro para o topo
typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

// Struct principal que viaja por todo o programa - STACKS A e B
typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

// stack_init.c
t_node	*node_new(int value);
t_stack	*stack_new(void);
void	stack_push_top(t_stack *stack, t_node *node);
void	stack_free(t_stack *stack);
void	data_free(t_stacks *data);

// stack_utils.c
int		is_sorted(t_stack *stack);
void	assign_indices(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		get_size(t_stack *stack);

// parse.c
t_stacks	*parse_args(int argc, char **argv);
void		ft_error(t_stacks *data);

// ops_swap.c
void	sa(t_stacks *data);
void	sb(t_stacks *data);
void	ss(t_stacks *data);

// ops_push.c
void	pa(t_stacks *data);
void	pb(t_stacks *data);

// ops_rotate.c
void	ra(t_stacks *data);
void	rb(t_stacks *data);
void	rr(t_stacks *data);

// ops_rrotate.c
void	rra(t_stacks *data);
void	rrb(t_stacks *data);
void	rrr(t_stacks *data);

// Estrategias
void	sort_simple(t_stacks *data);   // insertion / selection
void	sort_medium(t_stacks *data);   // chunk
void	sort_complex(t_stacks *data);  // radix
void	sort_adaptive(t_stacks *data); // depois

// disorder.c
double	compute_disorder(t_stack *s);

// utils.c
int		ft_atoi_safe(char *str, int *out);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
int		has_duplicate(t_stack *s, int value);
void	print_stack(t_stack *s);
int		find_max_pos(t_stack *s);

#endif