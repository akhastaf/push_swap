/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:03:38 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:41:05 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	from_a_to_b(t_stack **a, t_stack **b, t_range r, int *chunk)
{
	int	l;
	int	i;

	l = stack_count(*a);
	i = 0;
	while (i < l)
	{
		if (stack_count(*a) == 5)
			sort_five(a, b, chunk);
		if (r.s <= (*a)->data && (*a)->data <= r.e)
			exec_opr(a, b, *chunk, "pb");
		else
			exec_opr(a, b, 0, "ra");
		if (*a && r.s <= (*a)->data && (*a)->data <= r.e)
		{
			exec_opr(a, b, *chunk, "pb");
			i++;
		}
		i++;
	}
}
