/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:26 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 16:56:56 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_position(t_stack *a, int data)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->data < data)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
