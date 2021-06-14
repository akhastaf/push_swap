/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:54:35 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:19:34 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	swap(t_stack **s)
{
	int	tmp1;
	int	chunk1;
	int	tmp2;
	int	chunk2;

	if (!s)
		return ;
	if (stack_count(*s) > 1)
	{
		chunk1 = (*s)->chunk;
		tmp1 = pop(s);
		chunk2 = (*s)->chunk;
		tmp2 = pop(s);
		push(s, tmp1, chunk1);
		push(s, tmp2, chunk2);
	}
}

void	swap_s(t_stack **s1, t_stack **s2)
{
	swap(s1);
	swap(s2);
}

void	push_a(t_stack **a, t_stack **b, int chunk)
{
	int	tmp;

	if (*b)
	{
		tmp = pop(b);
		push(a, tmp, chunk);
	}
}

void	push_b(t_stack **a, t_stack **b, int chunk)
{
	int	tmp;

	if (*a)
	{
		tmp = pop(a);
		push(b, tmp, chunk);
	}
}
