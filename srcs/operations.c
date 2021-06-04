/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:54:35 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/04 17:57:38 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void    swap(t_stack **s)
{
    int tmp1;
    int chunk1;
    int tmp2;
    int chunk2;
    
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

void    swap_s(t_stack **s1, t_stack **s2)
{
    swap(s1);
    swap(s2);
}

void    push_a(t_stack **a, t_stack **b, int chunk)
{
    int tmp;

    if (*b)
    {
        tmp = pop(b);
        push(a, tmp, chunk);
    }
}

void    push_b(t_stack **a, t_stack **b, int chunk)
{
    int tmp;

    if (*a)
    {
        tmp = pop(a);
        push(b, tmp, chunk);
    }
}

void    rotate(t_stack **s)
{
    t_stack *tmp;
    t_stack *new;

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
            break;
        tmp = tmp->next;
    }
    tmp->next = new;
}

void    rotate_r(t_stack **s1, t_stack **s2)
{
    rotate(s1);
    rotate(s2);
}

void    reverse_rotate(t_stack **s)
 {
    t_stack *tmp;
    t_stack *p;
    
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

void    reverse_rotate_r(t_stack **s1, t_stack **s2)
 {
     reverse_rotate(s1);
     reverse_rotate(s2);
 }