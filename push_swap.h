/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:10:08 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 19:53:17 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
// bench stats
typedef struct s_bench_stats
{
	int		disorder;
	char	*strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench_stats;

// structs para flags
typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

typedef struct s_pointer_bench_flag
{
	t_bench_stats	*bench;
	t_flags			*flags;
}	t_ptr_b_f;

// Nodes para indexacao
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

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
t_node		*node_new(int value, t_stacks *data, t_ptr_b_f ptrs_b_f);
t_stack		*stack_new(void);
void		stack_addback(t_stack *stack, t_node *node);
void		stack_free(t_stack *stack);
void		data_free(t_stacks *data, t_bench_stats *bench, t_flags *flags);

// stack_utils.c
int			is_sorted(t_stack *stack);
void		assign_indices(t_stack *stack);
int			find_min_pos(t_stack *stack);

// parse.c
t_stacks	*parse_args(char **argv, t_ptr_b_f ptrs_b_f);
void		ft_error(t_stacks *data, t_ptr_b_f ptrs_b_f, char **splitted);

// ops_swap.c
void		sa(t_stacks *data, int print, t_bench_stats *bench_stats);
void		sb(t_stacks *data, int print, t_bench_stats *bench_stats);
void		ss(t_stacks *data, int print, t_bench_stats *bench_stats);

// ops_push.c
void		pa(t_stacks *data, int print, t_bench_stats *bench_stats);
void		pb(t_stacks *data, int print, t_bench_stats *bench_stats);
// ops_rotate.c
void		ra(t_stacks *data, int print, t_bench_stats *bench_stats);
void		rb(t_stacks *data, int print, t_bench_stats *bench_stats);
void		rr(t_stacks *data, int print, t_bench_stats *bench_stats);

// ops_rrotate.c
void		rra(t_stacks *data, int print, t_bench_stats *bench_stats);
void		rrb(t_stacks *data, int print, t_bench_stats *bench_stats);
void		rrr(t_stacks *data, int print, t_bench_stats *bench_stats);

// Estrategias
void		sort_simple(t_stacks *data, int print, t_bench_stats *bench_stats);
void		sort_medium(t_stacks *data, int print, t_bench_stats *bench_stats);
void		sort_complex(t_stacks *data, int print, t_bench_stats *bench_stats);
void		sort_adaptive(t_stacks *data, int print,
				t_bench_stats *bench_stats);

// disorder.c
double		compute_disorder(t_stack *s);

// utils.c
int			ft_atoi_safe(char *str, int *out);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *str, int fd);
int			has_duplicate(t_stack *stack, int value);
void		print_stack(t_stack *stack);
int			find_max_pos(t_stack *stack);
int			ft_strcmp(const char *s1, const char *s2);
t_flags		*check_flags(char **argv);
void		choose_what_to_do(t_stacks *data, t_flags *flags,
				t_bench_stats *bench);
int			sum_flags(t_flags *flags);
void		free_memmory_if_not_data(t_flags *flags, t_bench_stats *bench);

#endif