/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:04:27 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 18:13:10 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first(t_stack **a, t_stack **b, int *chunk)
{
	t_stack	*tmp;
	int		chunks;
	int		i;
	int		l;
	t_range	r;

	l = stack_count(*a);
	if (l == 100)
		chunks = 5;
	else if (l == 500)
		chunks = 11;
	tmp = *a;
	i = 0;
	while (i < l)
	{
		r.s = i;
		r.e = i + (l / chunks);
		from_a_to_b(a, b, r, chunk);
		i += (l / chunks);
		(*chunk)++;
	}
}
