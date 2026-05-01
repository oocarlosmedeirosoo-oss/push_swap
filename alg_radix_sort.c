/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_radix_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:13:54 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/30 23:02:42 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

All strategies are implemented in C and must generate sequences of Push_swap operations to perform the sorting. This means:
• Your C algorithms analyze the input and generate the appropriate sequence of
operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.
• The output of your strategy is the sequence of these operations that sorts the stack.
• When you state a complexity class, it must reflect the cost measured in number of Push_swap operations generated, not the theoretical complexity of a
classical array-based algorithm.