/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chunkempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:01:49 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 16:54:52 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_chunkempty(t_stack *a, int chunk)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
