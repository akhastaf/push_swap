/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:01 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 18:27:51 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	second(t_stack **a, t_stack **b, int *chunk)
{
	int	p;
	int	n;
	int	l;

	p = (*chunk);
	while (*b && p > 0)
	{
		while (!is_chunkempty(*b, *chunk))
		{
			n = get_pofhigher(*b, *chunk);
			l = stack_count(*b);
			if (n == 1)
				exec_opr(a, b, 0, "sb");
			else if (n >= (l / 2))
				exec_loop(a, b, "rrb", l - n);
			else
				exec_loop(a, b, "rb", n);
			exec_opr(a, b, *chunk, "pa");
		}
		(*chunk)--;
	}
}
