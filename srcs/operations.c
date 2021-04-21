/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:54:35 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/21 14:54:06 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void    swap(t_stack **s)
{
    int tmp1;
    int tmp2;
    
    if (stack_count(*s) > 1)
    {
        tmp1 = pop(s);
        tmp2 = pop(s);
        push(s, tmp1);
        push(s, tmp2);
    }
}

void    swap_s(t_stack **s1, t_stack **s2)
{
    swap(s1);
    swap(s2);
}

void    push_a(t_stack **a, t_stack **b)
{
    int tmp;

    if (*b)
    {
        tmp = pop(b);
        push(a, tmp);
    }
}

void    push_b(t_stack **a, t_stack **b)
{
    int tmp;

    if (*a)
    {
        tmp = pop(a);
        push(b, tmp);
    }
}

void    rotate(t_stack **s)
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
        push(s, tmp->data);
        free(tmp);
    }   
}

void    rotate_r(t_stack **s1, t_stack **s2)
{
    rotate(s1);
    rotate(s2);
}

void    reverse_rotate(t_stack **s)
 {
     t_stack *tmp1;
     t_stack *tmp2;

     tmp1 = malloc(sizeof(t_stack));
     tmp1->data = pop(s);
     tmp1->next = NULL;

    tmp2 = *s;
     while (tmp2)
     {
         if (!tmp2->next)
         {
            tmp2->next = tmp1;
             break ;
         }
         tmp2 = tmp2->next;
     }
 }

void    reverse_rotate_r(t_stack **s1, t_stack **s2)
 {
     reverse_rotate(s1);
     reverse_rotate(s2);
 }