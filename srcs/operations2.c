/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:20:15 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:20:59 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->data = (*s)->data;
	new->chunk = (*s)->chunk;
	new->next = NULL;
	tmp = (*s);
	*s = (*s)->next;
	free(tmp);
	tmp = (*s);
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	rotate_r(t_stack **s1, t_stack **s2)
{
	rotate(s1);
	rotate(s2);
}

void	reverse_rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*p;

	if (stack_count(*s) > 1)
	{
		tmp = *s;
		while (tmp->next)
		{
			p = tmp;
			tmp = tmp->next;
		}
		p->next = NULL;
		push(s, tmp->data, tmp->chunk);
		free(tmp);
	}
}

void	reverse_rotate_r(t_stack **s1, t_stack **s2)
{
	reverse_rotate(s1);
	reverse_rotate(s2);
}
