/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:51 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 18:39:12 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*c;

	c = copy(*a);
	tmp = *a;
	while (tmp)
	{
		tmp->data = get_position(c, tmp->data);
		tmp = tmp->next;
	}
	clear_stack(&c, free);
}
