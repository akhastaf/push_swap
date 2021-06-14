/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_poflower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:57:03 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 16:57:39 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_poflower(t_stack *a, int chunk)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		p;

	tmp = a;
	min = tmp->data;
	p = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->data < min && tmp->chunk == chunk)
		{
			min = tmp->data;
			p = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (p);
}
