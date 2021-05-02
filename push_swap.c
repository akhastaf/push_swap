/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:33:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/02 14:44:10 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
void    exec_opr(t_stack **a, t_stack **b, int chunk, char *opr)
{
    ft_putendl_fd(opr, 1);
    do_opr(a, b, chunk, opr);
}

void    exec_loop(t_stack **a, t_stack **b,int chunk, char *opr, int i)
{
    while (i > 0)
    {
        exec_opr(a, b, chunk, opr);
        i--;
    }
}


void    sort_three(t_stack **a)
{
    while (!check_sort(*a, NULL))
    {
        if ((*a)->data > (*a)->next->data)
            exec_opr(a, NULL, 0, "sa");
        if ((*a)->next->data > ((t_stack*)(*a)->next->next)->data)
            exec_opr(a, NULL, 0, "ra");
    }
}

// void    sort_five(t_stack **a, t_stack **b)
// {
//     t_stack *tmp;
//     int     t;
//     int     i;
  
//     exec_opr(a, b, "pb");
//     exec_opr(a, b, "pb");
//     sort_three(a);
//     while (b)
//     {
//         exec_opr(a, b, "pa");
//         tmp = *a;
//         t = peek_s(tmp);
//         i = 0;
//         tmp = tmp->next;
//         while (tmp)
//         {
//             if (tmp->data < t)
//                 i++;
//             tmp = tmp->next;
//         }
//         printf("%d\n", i);
//         if (i > (count_stack(*a) / 2))
//             exec_loop(a, NULL, "rra", i - (count_stack(*a) / 2));
//         else if (i < (count_stack(*a) / 2))
//             exec_loop(a, NULL, "rra", i);
//     }
    
// }

int get_last(t_stack *a)
{
    while (a->next)
        a = a->next;
    return (a->data);
}
t_stack *copy(t_stack *a)
{ 
    t_stack *tmp;
    t_stack *new;

    new = NULL;
    tmp = a;
    while(tmp)
    {
        push(&new, tmp->data, tmp->chunk);
        tmp = tmp->next;
    }
    return new;
}


int     is_valid(t_stack *s, int pivot)
{
    while (s)
    {
        if (s->data < pivot)
            return (1);
        s = s->next;
    }
    return (0);
}


void    half(t_stack **a, t_stack **b, int p)
{
    t_stack *tmp;
    int last;

    tmp = *a;
    while (is_valid(*a, p))
    {
        last = get_last(*a);
        if ((*a)->data < p)
            exec_opr(a, b, g_chunk, "pb");
        else if (last < p)
        {
            exec_opr(a, b, g_chunk, "ra");
            exec_opr(a, b, g_chunk, "pb");
        }
        else
            exec_opr(a, b, g_chunk, "rra");
    }
}
int pivot(t_stack *a)
{
    t_stack *tmp;
    t_stack *tmp1;
    t_stack *c;
    int s;
    int l; 
    c = copy(a);
    tmp1 = c;
    while (tmp1)
    {
        tmp = c;
        while (tmp)
        {
            if (tmp->next && tmp->data > tmp->next->data)
            {
                s = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = s;
            }
            tmp = tmp->next;
        }
        tmp1 = tmp1->next;
    }
    l = stack_count(a);
    tmp = c;
    s = 0;
    while (tmp && s < l/2)
    {
        tmp = tmp->next;
        s++;
    }
    return (tmp->data);
}

void sort(t_stack **a, t_stack **b)
{
    int p;

    if (!(*a) || count_stack(*a) <= 2)
        return ;
    p = pivot(*a);
    g_chunk++;
    half(a, b, p);
    sort(a, b);
}

int     main(int ac, char **av)
{
    t_stack     *a;
    t_stack     *b;
    int         c;

    a = NULL;
    b = NULL;
    g_chunk = 0;
    if (ac > 1)
    {
         get_numbers(&a, ac - 1, av);
         
        c = count_stack(a);
        if (c == 3)
            sort_three(&a);
        // else if (c == 5)
        //     sort_five(&a, &b);
        else
            sort(&a, &b);
         print_stack(a);
         print_stack(b);
    }
}