#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// bench stats
typedef struct bench_stats
{
	int		disorder;
	char	*strategy;
	int		total_ops;
	int 	sa;
	int 	sb;
	int 	ss;
	int 	pa;
	int 	pb;
	int 	ra;
	int 	rb;
	int 	rr;
	int 	rra;
	int 	rrb;
	int 	rrr;
}	t_bench_stats;

// structs para flags
typedef struct s_flags_values
{
	int simple;
	int medium;
	int complex;
	int adaptive;
	int bench;
}	t_flags_values;

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
void	stack_addback(t_stack *stack, t_node *node);
void	stack_free(t_stack *stack);
void	data_free(t_stacks *data);

// stack_utils.c
int		is_sorted(t_stack *stack);
void	assign_indices(t_stack *stack);
int		find_min_pos(t_stack *stack);

// parse.c
t_stacks	*parse_args(int argc, char **argv);
void		ft_error(t_stacks *data);

// ops_swap.c
void	sa(t_stacks *data, int print);
void	sb(t_stacks *data, int print);
void	ss(t_stacks *data, int print);

// ops_push.c
void	pa(t_stacks *data, int print);
void	pb(t_stacks *data, int print);
// ops_rotate.c
void	ra(t_stacks *data, int print);
void	rb(t_stacks *data, int print);
void	rr(t_stacks *data, int print);

// ops_rrotate.c
void	rra(t_stacks *data, int print);
void	rrb(t_stacks *data, int print);
void	rrr(t_stacks *data, int print);

// Estrategias
void	sort_simple(t_stacks *data, int print, t_bench_stats *bench_stats);   // insertion / selection
void	sort_medium(t_stacks *data, int print, t_bench_stats *bench_stats);   // chunk
void	sort_complex(t_stacks *data, int print, t_bench_stats *bench_stats);  // radix
void	sort_adaptive(t_stacks *data, int print, t_bench_stats *bench_stats); // depois

// disorder.c
double	compute_disorder(t_stack *s);

// utils.c
int		ft_atoi_safe(char *str, int *out);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *str, int fd);
int		has_duplicate(t_stack *stack, int value);
void	print_stack(t_stack *stack);
int		find_max_pos(t_stack *stack);


t_flags_values	*check_flags(char **argv);
#endif