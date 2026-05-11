/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:42:11 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/11 20:02:58 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench_stats	*ini_bench(void)
{
	t_bench_stats	*bench;

	bench = malloc(sizeof(t_bench_stats));
	if (!bench)
		return (NULL);
	bench->disorder = 0.0;
	bench->strategy = NULL;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	return (bench);
}

void	print_bench_stats(t_bench_stats *bench)
{
	if (!bench)
		return ;
	ft_printf("[bench] disorder: %i.", bench->disorder / 100);
	if ((bench->disorder % 100) == 0)
		ft_printf("00%%\n");
	else
		ft_printf("%i%%\n", bench->disorder % 100);
	ft_printf("[bench] strategy: %s\n", bench->strategy);
	ft_printf("[bench] total_ops: %d\n", bench->total_ops);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}

t_ptr_b_f	pointers_to_bench_flags(t_bench_stats *bench, t_flags *flags)
{
	t_ptr_b_f	ptrs_b_f;

	ptrs_b_f.bench = bench;
	ptrs_b_f.flags = flags;
	return (ptrs_b_f);
}

static void	ini_var(t_stacks **data, t_flags **flags, t_bench_stats **bench)
{
	*flags = NULL;
	*bench = NULL;
	*data = NULL;
}

int	main(int argc, char **argv)
{
	t_stacks		*data;
	t_flags			*flags;
	t_bench_stats	*bench;

	if (argc < 2)
		return (0);
	ini_var(&data, &flags, &bench);
	argv++;
	if ((*argv)[0] == '-' && (*argv)[1] == '-')
		flags = check_flags(argv);
	argv += sum_flags(flags);
	bench = ini_bench();
	if (*argv)
		data = parse_args(argv, pointers_to_bench_flags(bench, flags));
	if (!data)
		return (free_memmory_if_not_data(flags, bench), 1);
	if (is_sorted(data->a))
		return (data_free(data, bench, flags), 0);
	bench->disorder = (int)(compute_disorder(data->a) * 10000);
	assign_indices(data->a);
	choose_what_to_do(data, flags, bench);
	if (flags && flags->bench)
		print_bench_stats(bench);
	data_free(data, bench, flags);
	return (0);
}
