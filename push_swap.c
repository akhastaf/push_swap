/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:33:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 18:40:01 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_three(t_stack **a)
{
	while (!check_sort(*a, NULL))
	{
		if ((*a)->data > (*a)->next->data)
			exec_opr(a, NULL, 0, "sa");
		if ((*a)->next->data > ((t_stack *)(*a)->next->next)->data)
			exec_opr(a, NULL, 0, "rra");
	}
}

void	sort_five(t_stack **a, t_stack **b, int *chunk)
{
	int	p;
	int	i;
	int	l;

	i = 0;
	while (i < 2)
	{
		l = stack_count(*a);
		p = get_poflower(*a, 0);
		if (p == 1)
			exec_opr(a, b, 0, "sa");
		else if (p > (l / 2))
			exec_loop(a, b, "rra", l - p);
		else
			exec_loop(a, b, "ra", p);
		exec_opr(a, b, *chunk, "pb");
		i++;
	}
	sort_three(a);
	exec_opr(a, b, *chunk, "pa");
	exec_opr(a, b, *chunk, "pa");
}

void	sort(t_stack **a, t_stack **b)
{
	int	c;
	int	chunk;

	chunk = 1;
	c = stack_count(*a);
	if (c == 3)
		sort_three(a);
	else if (c == 5)
		sort_five(a, b, &chunk);
	else
	{
		first(a, b, &chunk);
		second(a, b, &chunk);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		get_numbers(&a, ac - 1, av);
		fill_stack(&a);
		if (!check_sort(a, b))
			sort(&a, &b);
		clear_stack(&a, free);
	}
	return (0);
}
