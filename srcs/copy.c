/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:58:31 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:13:58 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_stack	*copy(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*new;

	new = NULL;
	tmp = a;
	while (tmp)
	{
		push(&new, tmp->data, tmp->chunk);
		tmp = tmp->next;
	}
	return (new);
}
