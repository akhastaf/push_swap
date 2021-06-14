/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pofhigher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:00:50 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 16:58:13 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pofhigher(t_stack *a, int chunk)
{
	t_stack	*tmp;
	int		max;
	int		i;
	int		p;

	tmp = a;
	max = tmp->data;
	p = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->data > max && tmp->chunk == chunk)
		{
			max = tmp->data;
			p = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (p);
}
