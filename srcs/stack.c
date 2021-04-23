/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:47:51 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/23 15:05:12 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int     push(t_stack **stack, int data)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return -1;
    new->data = data;
    new->next = *stack;
    *stack = new;
    return (1);
}

int    pop(t_stack **stack)
{
    int data;
    t_stack *tmp;
    if (*stack == NULL)
        return (MAX_INT);
    tmp = *stack;
    data = tmp->data;
    *stack = tmp->next;
    free(tmp);
    return (data);
}

int    peek_s(const t_stack *stack)
{
    if (!stack)
        return (MAX_INT);
    return (stack->data);
}

int     stack_count(t_stack *s)
{
    t_stack *tmp;
    int i;
    
    tmp = s;
    i = 0;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

void    clear_stack(t_stack **stack, void (*f)(void *))
{
    t_stack *tmp;

    if (*stack)
    {
        while (*stack)
        {
            tmp = *stack;
            *stack = tmp->next;
            f(tmp);
        }
    }
}

int     count_stack(t_stack *s)
{
    t_stack *tmp;
    int     i;
    
    tmp = s;
    i = 0;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

void    print_stack(t_stack *s)
{
    t_stack *tmp;

    tmp = s;
    printf("=========================\n");
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next; 
    }
    printf("=========================\n");
}