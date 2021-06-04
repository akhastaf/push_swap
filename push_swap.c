/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:33:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/04 19:02:20 by akhastaf         ###   ########.fr       */
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


int     is_less(t_stack *s, int pivot)
{
    while (s)
    {
        if (s->data < pivot)
            return (1);
        s = s->next;
    }
    return (0);
}

int     is_greater(t_stack *s, int pivot)
{
    while(s)
    {
        if (s->data > pivot)
            return (1);
        s = s->next;
    }
    return (0);
}


void    from_a_to_b(t_stack **a, t_stack **b, int p)
{
    t_stack *tmp;
    int last;

    tmp = *a;
    while (is_less(*a, p))
    {
        // printf("******************************* first pivot : %d\n", p);
        // printf("********************** this stack A\n");
        // print_stack(*a);
        // printf("********************** this stack B\n");
        // print_stack(*b);
        last = get_last(*a);
        if ((*a)->data < p)
            exec_opr(a, b, g_chunk, "pb");
        else if (last < p)
        {
            exec_opr(a, b, 0, "rra");
            exec_opr(a, b, g_chunk, "pb");
        }
        else
            exec_opr(a, b, 0, "ra");
        // printf("******************************* pivot : %d\n", p);
        // printf("********************** this stack A");
        // print_stack(*a);
        // printf("********************** this stack B");
        // print_stack(*b);
    }
}

t_stack     *get_chunk(t_stack *a, int chunk)
{
    t_stack *tmp;
    t_stack *new;

    new = NULL;
    tmp = a;
    while (tmp)
    {
        if (tmp->chunk == chunk)
            push(&new, tmp->data, chunk);
        tmp = tmp->next;
    }
    return new;
}

int    get_higher(t_stack *a, int p)
{
    t_stack *t;
    int i;

    t = a;
    i = 1;
    while (t)
    {
        if (t->data <= p)
            i++;
        else if (t->data > p)
            break ;
        t = t->next;
    }
    return i;
}

int     get_pofhigher(t_stack *a, int chunk)
{
    t_stack *tmp;
    int     max;
    int     i;
    int     p;

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
void    from_b_to_a(t_stack **a, t_stack **b, int p)
{
    t_stack *tmp;
    int i;
    int l;

    tmp = *b;
    while (is_greater(*b, p))
    {   
        // printf("******************************* second pivot : %d\n", p);
        // printf("********************** this stack A\n");
        // print_stack(*a);
        // printf("********************** this stack B\n");
        // print_stack(*b);
        if ((*b)->data == p)
            exec_opr(a, b, 0, "sb");
        if ((*b)->data > p)
            exec_opr(a, b, g_chunk, "pa");
        else if ((*b)->data < p)
        {
            i = get_higher(*b, p);
            // printf("position %d\n", i);
            l = count_stack(*b);
            if (i == 1)
                exec_opr(a, b, 0, "sb");
            else if (i >= (l / 2))
                exec_loop(a, b, 0, "rrb", l - i + 1);
            else
                exec_loop(a, b, 0, "rb", i - 1);
            // if (i == 1)
            //     i++;
            // exec_loop(a, b, 0, "rrb", i - 1);
            exec_opr(a, b, g_chunk, "pa");
            if (i >= (l / 2))
                exec_loop(a, b, 0, "rb", l - i);
            else
                exec_loop(a, b, 0, "rrb", i - 1);
            // if ((*b)->data > p)
            //     exec_opr(a, b, g_chunk, "pa");
            // exec_loop(a, b, 0, "rb", i - 1);
        }
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

void    first(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int p;
    
    if (check_sort(*a, NULL) || !(*a))
        return ;
    tmp = get_chunk(*a, (*a)->chunk);
    if (!(*a) || count_stack(*a) <= 2)
    {
        if (count_stack(*a) == 2 && (*a)->data > (*a)->next->data)
            exec_opr(a, NULL, 0, "sa");  
        return ;
    }
    if (count_stack(tmp) == 2)
    {
        if ((*a)->data > (*a)->next->data)
            exec_opr(NULL, b, 0, "sa");
        g_chunk++;
        exec_opr(a, b, g_chunk, "pb");
        exec_opr(a, b, g_chunk, "pb");
    }
    else if (count_stack(tmp) == 1)
    {
        g_chunk++;
        exec_opr(a, b, g_chunk, "pb");
    }
    else
    {
        p = pivot(tmp);
        g_chunk++;
        from_a_to_b(a, b, p);
    }
    first(a, b);
}

int     get_bigger_chunk(t_stack *s)
{
    t_stack *tmp;
    int max;
    
    tmp = s;
    max = 0;
    while (tmp)
    {
        if (tmp->chunk > max)
            max = tmp->chunk;
        tmp = tmp->next;
    }
    return max;
}

int get_max(t_stack *a)
{
    t_stack *tmp;
    int     max;

    max = 0;
    tmp = a;
    while (tmp)
    {
        if (tmp->data > max)
            max = tmp->data;
        tmp = tmp->next;
    }
    return (max);
}

int is_chunkempty(t_stack *a, int chunk)
{
    t_stack *tmp;
    
    tmp = a;
    while (tmp)
    {
        if (tmp->chunk == chunk)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

void    second(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    
    int p;
    int n;
    int l;

    p = g_chunk;
    // printf("first chunk %d\n", p);
    while (*b && p > 0)
    {
        while (!is_chunkempty(*b, g_chunk))
        {
            // printf("chunk %d\n", tmp->chunk);
            tmp = get_chunk((*b), g_chunk);
            n = get_pofhigher(*b, g_chunk);
            l = count_stack(*b);
            // printf("count of b : %d\n", l);
            if (n == 1)
                exec_opr(a, b, 0, "sb");
            else if (n >= (l / 2))
                exec_loop(a, b, 0, "rrb", l - n);
            else
                exec_loop(a, b, 0, "rb", n);
            exec_opr(a, b, g_chunk, "pa");
        }
        g_chunk--;
    }
    // p = 0;
    // if (!(*b))
    //     return ;
    // tmp = get_chunk(*b, (*b)->chunk);
    // if (count_stack(*b) <= 2)
    // {
    //     if (count_stack(*b) == 2 && (*b)->data < (*b)->next->data)
    //         exec_opr(NULL, b, 0, "sb");
    //     if (*b)
    //     {
    //         g_chunk++;
    //         exec_opr(a, b, g_chunk, "pa");
    //     }
    //     if (*b)
    //     {
    //         g_chunk++;
    //         exec_opr(a, b, g_chunk, "pa");
    //     }
    //     return ;
    // }
    // if (count_stack(tmp) == 2)
    // {
    //     if ((*b)->data < (*b)->next->data)
    //         exec_opr(NULL, b, 0, "sb");
    //     g_chunk++;
    //     exec_opr(a, b, g_chunk, "pa");
    //     exec_opr(a, b, g_chunk, "pa");
    // }
    // else if (count_stack(tmp) == 1)
    // {
    //     g_chunk++;
    //     exec_opr(a, b, g_chunk, "pa");
    // }
    // else
    // {
    //     p = pivot(tmp);
    //     g_chunk++;
    //     from_b_to_a(a, b, p);
    // }
    // if (!check_sort(*a, NULL))
    //     first(a,b);
    // second(a, b);
}



void sort(t_stack **a, t_stack **b)
{
    g_chunk = 0;
    // while (!check_sort(*a, *b))
    // {
        first(a, b);
        // print_stack(*a);
        // print_stack(*b);
        printf("max chunk in A %d\n", g_chunk);
        second(a, b);
        // print_stack(*a);
        // print_stack(*b);
    // }
}

int     main(int ac, char **av)
{
    t_stack     *a;
    t_stack     *b;
    int         c;

    a = NULL;
    b = NULL;
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
        //printf("max chunk %d\n", g_chunk);
        // print_stack(a);
        // print_stack(b);
    }
}