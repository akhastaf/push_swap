/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:33:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/23 16:37:03 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
void    exec_opr(t_stack **a, t_stack **b, char *opr)
{
    ft_putendl_fd(opr, 1);
    do_opr(a, b, opr);
}
void    sort_three(t_stack **a)
{
    while (!check_sort(*a, NULL))
    {
        if ((*a)->data > (*a)->next->data)
            exec_opr(a, NULL, "sa");
        if ((*a)->next->data > ((t_stack*)(*a)->next->next)->data)
            exec_opr(a, NULL, "ra");
    }
}

void    sort_five(t_stack **a, t_stack **b)
{
    t_stack *tmp1;
    t_stack *tmp2;
  
    exec_opr(a, b, "pb");
    exec_opr(a, b, "pb");
    sort_three(a);
    exec_opr(a, b, "pa");
    
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
        else if (c == 5)
            sort_five(&a, &b);
         //print_stack(a);
    }
}